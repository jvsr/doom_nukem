/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 16:56:27 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:54:08 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "libft/ft_mem.h"
#include "serializer.h"
#include "error.h"

static void	read_secs(t_map *map, t_binary_read *bin_r)
{
	t_sector	*secs;
	t_uint64	i;

	map->sectors = ft_memalloc(sizeof(t_sector) * (map->sector_count + 1));
	i = 0;
	while (i < map->sector_count)
	{
		secs = read_sec(bin_r, map);
		ft_memcpy(map->sectors + i, secs, sizeof(t_sector));
		ft_memdel((void**)&secs);
		i++;
	}
}

t_map		*read_map(t_binary_read *bin_r)
{
	t_map	*map;

	map = ft_memalloc(sizeof(t_map));
	if (map == NULL)
		error_msg_errno("Unable To Allocated Level Data");
	map->sector_count = read_long(bin_r);
	read_secs(map, bin_r);
	map->has_skybox = (t_bool)read_char(bin_r);
	map->skybox = (t_texture)read_int(bin_r);
	map->has_won = (t_bool)read_char(bin_r);
	return (map);
}
