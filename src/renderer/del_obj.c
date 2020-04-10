/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_obj.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 10:28:44 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 10:59:31 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_bool.h"
#include "renderer.h"
#include "rinfo.h"

t_bool			del_obj(t_object *obj, t_sector *sec)
{
	t_list *lst;

	lst = sec->objects;
	while (lst != NULL)
	{
		if (lst->content == obj)
		{
			ft_lstunlink(&sec->objects, lst);
			ft_lstdelone(&lst, free_obj);
			sec->object_count--;
			return (TRUE);
		}
		lst = lst->next;
	}
	return (FALSE);
}
