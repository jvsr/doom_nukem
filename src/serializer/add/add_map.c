/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 16:48:41 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:55:30 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

static void	add_secs(t_map *map, t_binary *bin)
{
	t_uint64	i;

	i = 0;
	while (i < map->sector_count)
	{
		add_sec(map->sectors + i, bin, map);
		i++;
	}
}

void		add_map(t_map *map, t_binary *bin)
{
	add_long(map->sector_count, bin);
	add_secs(map, bin);
	add_char((char)map->has_skybox, bin);
	add_int(map->skybox, bin);
	add_char((char)map->has_won, bin);
}
