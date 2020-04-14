/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_clean_doors.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 15:17:25 by euan          #+#    #+#                 */
/*   Updated: 2020/04/14 20:26:15 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "rinfo.h"

static void	change_door(t_wall *wall, t_sector *wsec)
{
	t_wall		*tmp;
	t_sector	*sec;
	t_uint64	i;

	sec = wall->window;
	i = 0;
	while (i < sec->wall_count)
	{
		tmp = &sec->walls[i];
		if (tmp->is_door && tmp->window == wsec)
		{
			tmp->is_door = FALSE;
			tmp->is_portal = TRUE;
			tmp->texture.left[0] = TEXTURE_BRICK_WALL;
		}
		i++;
	}
}

void		convert_clean_doors(t_map *map)
{
	t_sector	*sec;
	t_wall		*wall;
	t_uint64	i;
	t_uint64	j;

	i = 0;
	while (i < map->sector_count)
	{
		sec = &map->sectors[i];
		j = 0;
		while (j < sec->wall_count)
		{
			wall = &sec->walls[j];
			if (wall->is_door)
				change_door(wall, sec);
			j++;
		}
		i++;
	}
}
