/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_wall.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 17:20:56 by euan          #+#    #+#                 */
/*   Updated: 2020/04/10 14:50:12 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

static int	get_portal(t_map *map, t_sector *sec)
{
	int i;

	i = 0;
	while (map->sectors + i != sec)
		i++;
	return (i);
}

void		add_wall(t_wall *wall, t_binary *bin, t_map *map)
{
	add_coord(&wall->corner_0, bin);
	add_coord(&wall->corner_1, bin);
	add_char((char)wall->is_portal, bin);
	add_char((char)wall->is_window, bin);
	add_anim(&wall->texture, bin);
	add_anim(&wall->win_tex, bin);
	add_coord(&wall->perc, bin);
	if (wall->decals == NULL)
		add_int(0, bin);
	else
	{
		add_int(1, bin);
		add_decal_list(wall->decals, bin);
	}
	add_char((char)wall->is_door, bin);
	if (wall->is_portal || wall->is_door || wall->is_window || map == NULL)
		add_int(get_portal(map, wall->window), bin);
	else
		add_int(-1, bin);
}
