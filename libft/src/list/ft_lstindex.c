/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 22:50:52 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:09:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstindex(t_list *lst, size_t index)
{
	while (lst != NULL && index > 0)
	{
		lst = lst->next;
		index--;
	}
	return (lst);
}
