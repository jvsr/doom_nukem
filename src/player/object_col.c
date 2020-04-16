/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   object_col.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 17:35:28 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:55:24 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_bool.h"
#include "libft/ft_mem.h"
#include "game.h"
#include "error.h"
#include "setting.h"
#include "player.h"
#include "rinfo.h"
#include "cmath.h"
#include "keymap.h"

#include <limits.h>

t_uint32	get_sector_id(t_map *map, t_sector *sec)
{
	t_uint32 i;

	i = 0;
	while (i < map->sector_count)
	{
		if (&map->sectors[i] == sec)
			return (i);
		i++;
	}
	return (4294967294);
}

static int	check_dist_objects(t_game *game, t_object *obj, t_tricoord coord)
{
	float	dist;
	int		tmp;

	tmp = 0;
	dist = get_distance(&game->player->pos, &obj->pos);
	if (get_distance(&coord.x, &obj->pos) <= obj->col_radius
	&& get_distance(&coord.x, &obj->pos) < dist)
		tmp |= 1;
	if (get_distance(&coord.y, &obj->pos) <= obj->col_radius
	&& get_distance(&coord.y, &obj->pos) < dist)
		tmp |= 2;
	if (get_distance(&coord.xy, &obj->pos) <= obj->col_radius
	&& get_distance(&coord.xy, &obj->pos) < dist)
		tmp |= 4;
	return (tmp);
}

void		check_objects(t_game *game, t_uint8 *col, t_tricoord coord)
{
	int			tmp;
	t_object	*obj;
	t_list		*objects;

	objects = game->map->sectors[game->player->cur_sector].objects;
	while (objects != NULL && *col != 7)
	{
		obj = objects->content;
		objects = objects->next;
		if (obj->size.y < game->player->heightoffset
		- game->player->player_height)
			continue ;
		tmp = check_dist_objects(game, obj, coord);
		if (tmp == 0)
			continue ;
		if (obj->can_col == TRUE)
			*col |= tmp;
		if (obj->on_collide)
			obj->on_collide(game,
			(void*)&game->map->sectors[game->player->cur_sector],
			obj, game->player);
		if (*col == 7)
			return ;
	}
}
