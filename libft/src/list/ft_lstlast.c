/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/23 01:15:44 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:09:33 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstlast(const t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return ((t_list *)lst);
}
