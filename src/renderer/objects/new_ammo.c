/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_ammo.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 13:55:49 by euan          #+#    #+#                 */
/*   Updated: 2020/04/10 13:58:36 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "textures.h"
#include "player.h"
#include "coord.h"
#include "rinfo.h"
#include "error.h"

t_object		*new_ammo(t_coord *pos, t_sector *parent)
{
	t_object *obj;

	obj = ft_memalloc(sizeof(t_object));
	if (obj == NULL)
		error_msg_errno("Unable to allocate key");
	ft_memcpy(&obj->pos, pos, sizeof(t_coord));
	obj->size = (t_coord){4, 4};
	obj->img = single_init(TEXUTRE_AMMO, obj);
	obj->is_enemy = FALSE;
	obj->can_col = FALSE;
	obj->col_radius = 1.0;
	obj->on_collide = ammo_pickup;
	if (parent == NULL)
		return (obj);
	ft_lstaddbck(&parent->objects, ft_lstnew(obj, sizeof(t_object)));
	parent->object_count++;
	return (obj);
}
