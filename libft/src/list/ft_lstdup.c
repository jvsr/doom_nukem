/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 16:03:21 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/08 15:58:23 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static t_list	*freeret(t_list **lst)
{
	ft_lstdel(lst, NULL);
	return (NULL);
}

t_list			*ft_lstdup(const t_list *lst)
{
	t_list	*current;
	t_list	*duplst;
	t_list	*prvlst;
	t_list	*retlst;

	if (lst == NULL)
		return (NULL);
	retlst = ft_lstnew(lst->content, lst->content_size);
	if (retlst == NULL)
		return (NULL);
	prvlst = retlst;
	current = lst->next;
	while (current != NULL)
	{
		duplst = ft_lstnew(current->content, current->content_size);
		if (duplst == NULL)
			return (freeret(&retlst));
		prvlst->next = duplst;
		prvlst = duplst;
		current = current->next;
	}
	return (retlst);
}
