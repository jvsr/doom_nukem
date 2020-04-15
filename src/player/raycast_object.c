/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_object.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 14:19:41 by euan          #+#    #+#                 */
/*   Updated: 2020/04/15 21:47:53 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "renderer.h"
#include "textures.h"
#include "setting.h"
#include "player.h"
#include "coord.h"
#include "rinfo.h"
#include "cmath.h"
#include "game.h"

static t_object	*get_closer(t_object *obj, t_object *prv, t_player *plyr)
{
	float a;
	float b;

	if (prv == NULL)
		return (obj);
	a = get_distance(&obj->pos, &plyr->pos);
	b = get_distance(&prv->pos, &plyr->pos);
	if (a < b)
		return (obj);
	return (prv);
}

static t_bool	collides(t_object *obj, SDL_Surface *dst)
{
	int half;

	half = dst->w / 2;
	return (obj->ssize.x < half && obj->ssize.y > half);
}

static t_object	*ray(t_sector *sec, t_coord *range, t_player *plyr,
					t_game *game)
{
	t_list		*lst;
	float		i;
	t_object	*obj;

	lst = sec->objects;
	obj = NULL;
	while (lst != NULL)
	{
		i = get_object_angle_on_screen(lst->content, plyr, range);
		if (i != -1 && ((t_object*)lst->content)->can_col)
			if (collides(lst->content, game->surface))
				obj = get_closer(lst->content, obj, plyr);
		lst = lst->next;
	}
	return (obj);
}

t_object		*handle_wall(t_game *game, t_player *plyr, t_sector *sec,
							t_coord *range)
{
	t_wall		*wall;
	t_sector	*cur;
	t_object	*obj;

	cur = sec;
	wall = raycast_wall(sec, plyr, FALSE, FALSE);
	if (wall == NULL || wall->is_portal == FALSE)
		return (NULL);
	if (wall->is_window)
		smash_glass(game, wall, sec);
	while (wall->is_portal == TRUE)
	{
		obj = ray(cur, range, plyr, game);
		if (obj != NULL)
			return (obj);
		wall = wall_ray(cur, sec, plyr, (t_bool[2]){FALSE, FALSE});
		if (wall == NULL)
			break ;
		if (wall->is_window)
			smash_glass(game, wall, sec);
		sec = cur;
		cur = wall->window;
	}
	return (NULL);
}

t_object		*raycast_object(t_game *game, t_map *map, t_player *plyr)
{
	t_sector	*sec;
	t_coord		range;
	t_object	*obj;

	sec = map->sectors + plyr->cur_sector;
	range.x = wrap_angle(plyr->angle - ((float)game->setting->fov / 2));
	range.y = wrap_angle(plyr->angle + ((float)game->setting->fov / 2));
	obj = ray(sec, &range, plyr, game);
	if (obj != NULL)
		return (obj);
	return (handle_wall(game, plyr, sec, &range));
}
