/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_key.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 11:17:13 by euan          #+#    #+#                 */
/*   Updated: 2020/04/02 11:28:12 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "textures.h"
#include "player.h"
#include "coord.h"
#include "rinfo.h"
#include "error.h"

t_object		*new_key(t_coord *pos, t_sector *parent)
{
	t_object *obj;

	obj = ft_memalloc(sizeof(t_object));
	if (obj == NULL)
		error_msg_errno("Unable to allocate key");
	ft_memcpy(&obj->pos, pos, sizeof(t_coord));
	obj->size = (t_coord){4, 4};
	obj->img = single_init(TEXTURE_KEYS, obj);
	obj->is_enemy = FALSE;
	obj->can_col = FALSE;
	obj->col_radius = 1.0;
	obj->on_collide = key_pickup;
	if (parent == NULL)
		return (obj);
	ft_lstaddbck(&parent->objects, ft_lstnew(obj, sizeof(t_object)));
	parent->object_count++;
	return (obj);
}
