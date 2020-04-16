/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_chair.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 11:02:19 by euan          #+#    #+#                 */
/*   Updated: 2020/04/02 11:27:50 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "textures.h"
#include "coord.h"
#include "rinfo.h"
#include "error.h"

t_object	*new_chair(t_coord *pos, float offset, t_sector *parent)
{
	t_object *obj;

	obj = ft_memalloc(sizeof(t_object));
	if (obj == NULL)
		error_msg_errno("Unable to allocate chair");
	ft_memcpy(&obj->pos, pos, sizeof(t_coord));
	obj->size = (t_coord){10, 10};
	obj->img = chair_init(obj, offset);
	obj->is_enemy = FALSE;
	obj->can_col = TRUE;
	obj->col_radius = 1.0;
	if (parent == NULL)
		return (obj);
	ft_lstaddbck(&parent->objects, ft_lstnew(obj, sizeof(t_object)));
	parent->object_count++;
	return (obj);
}
