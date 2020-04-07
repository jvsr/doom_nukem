/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_enemy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 11:10:19 by euan          #+#    #+#                 */
/*   Updated: 2020/04/02 11:27:58 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "textures.h"
#include "coord.h"
#include "rinfo.h"
#include "error.h"

t_object		*new_enemy(t_coord *pos, t_sector *parent)
{
	t_object *obj;

	obj = ft_memalloc(sizeof(t_object));
	if (obj == NULL)
		error_msg_errno("Unable to allocate enemy");
	ft_memcpy(&obj->pos, pos, sizeof(t_coord));
	obj->size = (t_coord){5, 15};
	obj->img = enemy_init(obj, TEXTURE_ENEMY0_F0);
	obj->is_enemy = TRUE;
	obj->can_col = TRUE;
	obj->col_radius = 1.0;
	if (parent == NULL)
		return (obj);
	ft_lstaddbck(&parent->objects, ft_lstnew(obj, sizeof(t_object)));
	parent->object_count++;
	return (obj);
}
