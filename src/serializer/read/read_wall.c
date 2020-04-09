/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_wall.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 21:54:04 by euan          #+#    #+#                 */
/*   Updated: 2020/04/08 16:09:06 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"
#include "error.h"

t_wall		*read_wall(t_binary_read *bin_r, t_map *map)
{
	t_wall	*wall;
	int		isec;

	wall = ft_memalloc(sizeof(t_wall));
	if (wall == NULL)
		error_msg_errno("Unable To Allocated Level Data");
	wall->corner_0 = read_coord(bin_r);
	wall->corner_1 = read_coord(bin_r);
	wall->is_portal = (t_bool)read_char(bin_r);
	wall->is_window = (t_bool)read_char(bin_r);
	wall->texture = read_anim(bin_r, NULL);
	wall->win_tex = read_anim(bin_r, NULL);
	wall->perc = read_coord(bin_r);
	if (read_int(bin_r) == 1)
		wall->decals = read_decal_list(bin_r);
	else
		wall->decals = NULL;
	wall->is_door = (t_bool)read_char(bin_r);
	isec = read_int(bin_r);
	if (isec == -1 || map == NULL)
		wall->window = NULL;
	else
		wall->window = map->sectors + isec;
	return (wall);
}
