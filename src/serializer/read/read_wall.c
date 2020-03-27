/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_wall.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 21:54:04 by euan           #+#    #+#                */
/*   Updated: 2020/03/27 22:00:14 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"

t_wall		*read_wall(t_binary_read *bin_r)
{
	t_wall *wall;

	wall = ft_memalloc(sizeof(t_wall));
	wall->corner_0 = read_coord(bin_r);
	wall->corner_1 = read_coord(bin_r);
	wall->is_portal = (t_bool)read_char(bin_r);
	wall->is_window = (t_bool)read_char(bin_r);
	wall->texture = read_anim(bin_r, NULL);
	wall->win_tex = read_anim(bin_r, NULL);
	wall->perc = read_coord(bin_r);
	wall->decals = read_decal_list(bin_r);
	wall->is_door = (t_bool)read_char(bin_r);
	return (wall);
}
