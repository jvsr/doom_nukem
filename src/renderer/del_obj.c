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

static t_bool	del(t_list *prv, t_list *cur)
{
	if (prv != NULL)
		prv->next = cur->next;
	cur->next = NULL;
	ft_lstdelone(&cur, free_obj);
	return (TRUE);
}

t_bool			del_obj(t_object *obj, t_sector *sec)
{
	t_list *lst;
	t_list *prv;

	lst = sec->objects;
	prv = NULL;
	while (lst != NULL)
	{
		if (lst->content == obj)
			return (del(prv, lst));
		prv = lst;
		lst = lst->next;
	}
	return (FALSE);
}
