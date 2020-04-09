/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raycast_object.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 14:19:41 by euan          #+#    #+#                 */
/*   Updated: 2020/04/09 11:26:53 by euan          ########   odam.nl         */
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

static t_bool	collides(t_object *obj, t_player *plyr)
{
	t_coord vec;
	t_coord	c0;
	t_coord c1;

	get_vector_from_points(&plyr->pos, &obj->pos, &vec);
	normalize_vector(&vec);
	vec = (t_coord){vec.y, vec.x};
	c0 = (t_coord){obj->pos.x + (vec.x * obj->col_radius),
		obj->pos.y + (vec.y * -obj->col_radius)};
	c1 = (t_coord){obj->pos.x + (vec.y * obj->col_radius), obj->pos.y +
		(vec.y * -obj->col_radius)};
	return (get_collision(&plyr->pos, &(t_coord){plyr->mag.cos, plyr->mag.sin},
		(t_coord[2]){c0, c1}, &vec) != NULL);
}

static t_object	*ray(t_sector *sec, t_coord *range, t_player *plyr)
{
	t_list		*lst;
	float		i;
	t_object	*obj;

	lst = sec->objects;
	obj = NULL;
	while (lst != NULL)
	{
		i = get_object_angle_on_screen(lst->content, plyr, range);
		if (i != -1)
			if (collides(lst->content, plyr))
				obj = get_closer(lst->content, obj, plyr);
		lst = lst->next;
	}
	return (obj);
}

t_object		*raycast_object(t_game *game, t_map *map, t_player *plyr)
{
	t_sector	*sec;
	t_coord		range;
	t_wall		*wall;
	t_object	*obj;

	sec = map->sectors + plyr->cur_sector;
	range.x = wrap_angle(plyr->angle - (game->setting->fov / 2));
	range.y = wrap_angle(plyr->angle + (game->setting->fov / 2));
	obj = ray(sec, &range, plyr);
	if (obj != NULL)
		return (obj);
	wall = raycast_wall(sec, plyr, FALSE, FALSE);
	if (wall->is_portal == FALSE)
		return (NULL);
	while (wall->is_portal == TRUE)
	{
		obj = ray(wall->window, &range, plyr);
		if (obj != NULL)
			return (obj);
		wall = wall_ray(wall->window, sec, plyr, (t_bool[2]){FALSE, FALSE});
		sec = wall->window;
	}
	return (NULL);
}
