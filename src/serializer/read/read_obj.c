/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_obj.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 13:13:15 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:54:05 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"
#include "player.h"
#include "error.h"

t_object	*read_obj(t_binary_read *bin_r)
{
	t_object	*obj;

	obj = ft_memalloc(sizeof(t_object));
	if (obj == NULL)
		error_msg_errno("Unable To Allocated Level Data");
	obj->pos = read_coord(bin_r);
	obj->size = read_coord(bin_r);
	obj->img = read_anim(bin_r, obj);
	obj->is_enemy = (t_bool)read_char(bin_r);
	obj->col_radius = read_float(bin_r);
	obj->can_col = (t_bool)read_char(bin_r);
	obj->on_collide = get_col_from_name(read_string(bin_r));
	if (obj->is_enemy)
		read_enemy(obj, bin_r);
	return (obj);
}
