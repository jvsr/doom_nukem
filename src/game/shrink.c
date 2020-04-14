/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shrink.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/14 17:06:33 by euan          #+#    #+#                 */
/*   Updated: 2020/04/14 17:07:38 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "map_editor.h"
#include "renderer.h"
#include "player.h"
#include "rinfo.h"
#include "game.h"

static void		shrinkwall(t_wall *wall)
{
	wall->corner_0 = (t_coord){wall->corner_0.x / SHRINK_SIZE,
		wall->corner_0.y / SHRINK_SIZE};
	wall->corner_1 = (t_coord){wall->corner_1.x / SHRINK_SIZE,
		wall->corner_1.y / SHRINK_SIZE};
}

void			shrink(t_map *map)
{
	t_uint64	i;
	t_list		*lst;
	t_object	*obj;
	t_uint64	j;

	i = 0;
	while (i < map->sector_count)
	{
		lst = map->sectors[i].objects;
		while (lst)
		{
			obj = lst->content;
			obj->pos = (t_coord){obj->pos.x / SHRINK_SIZE,
				obj->pos.y / SHRINK_SIZE};
			lst = lst->next;
		}
		j = 0;
		while (j < map->sectors[i].wall_count)
		{
			shrinkwall(&map->sectors[i].walls[j]);
			j++;
		}
		i++;
	}
}
