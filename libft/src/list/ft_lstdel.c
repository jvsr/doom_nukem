/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 18:35:27 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:41:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstdel(t_list **head, void (*del)(void *, size_t))
{
	if (head == NULL || *head == NULL)
		return ;
	if ((*head)->next != NULL)
		ft_lstdel(&(*head)->next, del);
	ft_lstdelone(head, del);
}
