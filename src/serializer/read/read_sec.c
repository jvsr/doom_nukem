/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_sec.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 16:23:28 by euan          #+#    #+#                 */
/*   Updated: 2020/04/09 13:21:55 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "serializer.h"
#include "error.h"

static void		read_walls(t_sector *sec, t_binary_read *bin_r, t_map *map)
{
	t_uint64	i;
	t_wall		*wall;

	i = 0;
	sec->walls = ft_memalloc(sizeof(t_wall) * (sec->wall_count + 1));
	while (i < sec->wall_count)
	{
		wall = read_wall(bin_r, map);
		ft_memcpy(sec->walls + i, wall, sizeof(t_wall));
		ft_memdel((void**)&wall);
		i++;
	}
}

static void		read_objs(t_sector *sec, t_binary_read *bin_r)
{
	t_uint64	i;

	i = 0;
	while (i < sec->object_count)
	{
		ft_lstaddbck(&sec->objects,
			ft_lstnew(read_obj(bin_r), sizeof(t_object)));
		i++;
	}
}

t_sector		*read_sec(t_binary_read *bin_r, t_map *map)
{
	t_sector	*sec;
	int			swall;

	sec = ft_memalloc(sizeof(t_sector));
	if (sec == NULL)
		error_msg_errno("Unable To Allocated Level Data");
	sec->wall_count = read_long(bin_r);
	sec->object_count = read_long(bin_r);
	read_walls(sec, bin_r, map);
	read_objs(sec, bin_r);
	sec->floor = read_float(bin_r);
	sec->ceil = read_float(bin_r);
	sec->floor_tex = read_int(bin_r);
	sec->ceil_tex = read_int(bin_r);
	sec->has_ceiling = (t_bool)read_char(bin_r);
	sec->light_value = read_float(bin_r);
	sec->has_slope = (t_bool)read_char(bin_r);
	sec->angle = read_float(bin_r);
	swall = read_int(bin_r);
	if (swall == -1)
		sec->swall = NULL;
	else
		sec->swall = &sec->walls[swall];
	return (sec);
}
