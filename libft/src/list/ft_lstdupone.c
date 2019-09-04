/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdupone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:54:49 by pholster       #+#    #+#                */
/*   Updated: 2019/08/23 15:56:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstdupone(const t_list *lst)
{
	t_list	*duplst;

	duplst = ft_lstnew_dup(lst->content, lst->content_size);
	if (duplst == NULL)
		return (NULL);
	return (duplst);
}
