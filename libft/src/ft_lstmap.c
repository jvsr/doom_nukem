/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:35:14 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*freeret(t_list **lst)
{
	ft_lstdel(lst, &ft_lstdelmem);
	return (NULL);
}

static t_list	*list_set(t_list *elem)
{
	t_list *new;

	new = ft_lstnew(elem->content, elem->content_size);
	if (new == NULL)
		return (NULL);
	return (new);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*retlst;
	t_list	*prvlst;
	t_list	*duplst;

	if (lst == NULL || f == NULL)
		return (NULL);
	retlst = list_set(f(lst));
	if (retlst == NULL)
		return (NULL);
	current = lst->next;
	prvlst = retlst;
	while (current != NULL)
	{
		duplst = list_set(f(current));
		if (duplst == NULL)
			return (freeret(&retlst));
		prvlst->next = duplst;
		prvlst = duplst;
		current = current->next;
	}
	return (retlst);
}
