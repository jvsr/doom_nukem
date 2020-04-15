/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy_move.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:54:16 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/14 22:09:19 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_list.h"
#include "libft/ft_printf.h"

#include "game.h"
#include "rinfo.h"
#include "cmath.h"
#include "enemy.h"
#include "player.h"

static t_bool	coll(t_coord c0, t_coord c1, t_coord c2, t_coord c3)
{
	t_coord b;
	t_coord d;
	t_coord c;
	t_coord dots;

	b = (t_coord){c1.x - c0.x, c1.y - c0.y};
	d = (t_coord){c3.x - c2.x, c3.y - c2.y};
	dots.x = b.x * d.y - b.y * d.x;
	if (dots.x == 0)
		return (FALSE);
	c = (t_coord){c2.x - c0.x, c2.y - c0.y};
	dots.y = (c.x * d.y - c.y * d.x) / dots.x;
	if (dots.y < 0 || dots.y > 1)
		return (FALSE);
	dots.y = (c.x * b.y - c.y * b.x) / dots.x;
	if (dots.y < 0 || dots.y > 1)
		return (FALSE);
	return (TRUE);
}

static void		move_enemy(t_object *object, t_sector *s, float a,
																float lastframe)
{
	size_t	i;
	float	xspeed;
	float	yspeed;

	object->img.offset = wrap_angle(a);
	xspeed = 0.15 * cosf(a * PI_R);
	xspeed = lerp_max(0, xspeed, lastframe / BASE_FRAME_TIME, INFINITY);
	yspeed = 0.15 * sinf(a * PI_R);
	yspeed = lerp_max(0, yspeed, lastframe / BASE_FRAME_TIME, INFINITY);
	i = 0;
	while (i < s->wall_count)
	{
		if (s->walls[i].is_portal == TRUE)
		{
			if (coll(object->pos,
			(t_coord){object->pos.x + xspeed, object->pos.y + yspeed},
			s->walls[i].corner_0, s->walls[i].corner_1))
				return ;
		}
		i++;
	}
	object->pos.x += xspeed;
	object->pos.y += yspeed;
	((t_enemy*)object->data)->state = ENEMY_MOVING;
}

void			enemy_move(t_game *game)
{
	size_t		i;
	size_t		j;
	t_object	*obj;
	const t_map	*map = game->map;

	i = 0;
	while (i < map->sector_count)
	{
		j = 0;
		while (j < map->sectors[i].object_count)
		{
			obj = ft_lstindex(map->sectors[i].objects, j)->content;
			if (obj != NULL && obj->data != NULL && check_enemy(game, obj))
				move_enemy(obj, &map->sectors[i],
					get_angle_between_points(&obj->pos, &game->player->pos),
					(float)game->lastframe);
			j++;
		}
		i++;
	}
}
