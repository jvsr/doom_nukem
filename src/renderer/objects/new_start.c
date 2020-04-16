/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_start.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 11:24:04 by euan          #+#    #+#                 */
/*   Updated: 2020/04/02 11:28:25 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "textures.h"
#include "player.h"
#include "coord.h"
#include "rinfo.h"
#include "error.h"

t_object		*new_start(t_coord *pos, t_sector *parent)
{
	t_object *obj;

	obj = ft_memalloc(sizeof(t_object));
	if (obj == NULL)
		error_msg_errno("Unable to allocate start");
	ft_memcpy(&obj->pos, pos, sizeof(t_coord));
	obj->size = (t_coord){4, 4};
	obj->img = single_init(TEXTURE_START, obj);
	obj->is_enemy = FALSE;
	obj->can_col = FALSE;
	obj->col_radius = 1.0;
	if (parent == NULL)
		return (obj);
	ft_lstaddbck(&parent->objects, ft_lstnew(obj, sizeof(t_object)));
	parent->object_count++;
	return (obj);
}
