/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:37:51 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/27 15:31:52 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_list.h"
#include "libft/ft_printf.h"

#include "gui.h"
#include "cmath.h"
#include "game.h"
#include "loop.h"
#include "player.h"

#include "rinfo.h"

static t_bool		coll(t_coord c0, t_coord c1, t_coord c2, t_coord c3)
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

void		move_enemy(t_object *object, t_sector *s, float a, float lastframe)
{
	size_t	i;
	float	xspeed;
	float	yspeed;

	xspeed = 0.15 * cosf(a * PI_R);
	xspeed = lerp_max(0, xspeed, lastframe / BASE_FRAME_TIME, INFINITY);
	yspeed = 0.15 * sinf(a * PI_R);
	yspeed = lerp_max(0, yspeed, lastframe / BASE_FRAME_TIME, INFINITY);
	i = 0;
	while (i < s->wall_count)
	{
		if (s->walls[i].is_portal == TRUE)
		{
			if (coll(object->pos, (t_coord){object->pos.x + xspeed, object->pos.y + yspeed},
			s->walls[i].corner_0, s->walls[i].corner_1))
				return ;
		}
		i++;
	}
	object->pos.x += xspeed;
	object->pos.y += yspeed;
}

void		check_enemy(t_game *game, t_sector *s, t_object *object, float lastframe)
{
	float	ang;
	t_coord	angl;
	t_coord	pos;
	const float	dist = get_distance(&game->player->pos, &object->pos);

	if (object->is_enemy == TRUE)
	{
		if (dist < 100)
		{
			if (dist > 5)
			{
				ang = get_angle_between_points(&object->pos, &game->player->pos);
				t_uint64 i = 0;
				while (i < game->map->sector_count) {
					t_uint64 j = 0;
					while (j < game->map->sectors[i].wall_count) {
						t_wall cur = game->map->sectors[i].walls[j];
						if (cur.is_portal == FALSE) {
							get_vector_from_angle(ang, &angl);
							if (get_collision(&object->pos, &angl, (t_coord[2]){cur.corner_0, cur.corner_1}, &pos))
							{
								t_coord newangl = {-(angl.x), -(angl.y)};
								if (get_collision(&game->player->pos, &newangl,
								(t_coord[2]){cur.corner_0, cur.corner_1}, &pos))
								{
									if (((t_enemy*)(object->data))->no_los)
										((t_enemy*)(object->data))->no_los(game, object);
									return ;
								}
							}
						}
						j++;
					}
					i++;
				}
				move_enemy(object, s, ang, lastframe);
			}
			if (((t_enemy*)(object->data))->on_los)
				((t_enemy*)(object->data))->on_los(game, object, game->player);
		}
		else if (((t_enemy*)(object->data))->no_los)
			((t_enemy*)(object->data))->no_los(game, object);
	}
}

void		enemy_move(t_game *game)
{
	size_t		i;
	size_t		j;
	t_list		*obj;
	const t_map	*map = game->map;

	i = 0;
	while (i < map->sector_count)
	{
		j = 0;
		while (j < map->sectors[i].object_count)
		{
			obj = ft_lstindex(map->sectors[i].objects, j);
			check_enemy(game, &map->sectors[i], obj->content,(float)game->lastframe);
			j++;
		}
		i++;
	}
}

void		loop_game(t_game *game)
{
	player_move(game);
	enemy_move(game);
	loop_game_gui(game);
	if (game->player->is_dead)
		player_died(game);
}
