/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstaddbck.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:28:18 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:08:10 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstaddbck(t_list **head, const t_list *new)
{
	t_list	*lst;

	if (*head == NULL)
	{
		*head = (t_list *)new;
		return ;
	}
	lst = *head;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = (t_list *)new;
}
