/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstunlink.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 17:41:05 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

t_list	*ft_lstunlink(t_list *head, t_list *lst)
{
	t_list	*current;

	current = head;
	if (head == NULL || lst == NULL || head == lst)
		return (NULL);
	while (current != NULL && current->next != lst)
		current = current->next;
	if (current == NULL)
		return (NULL);
	current->next = lst->next;
	return (lst);
}
