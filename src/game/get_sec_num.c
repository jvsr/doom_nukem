/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_sec_num.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 20:35:22 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 20:35:43 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rinfo.h"

int		get_sec_num(t_map *map, t_sector *sec)
{
	t_uint64	i;

	i = 0;
	while (i < map->sector_count)
	{
		if (sec == map->sectors + i)
			return (i);
		i++;
	}
	return (i - 1);
}
