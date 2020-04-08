/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstunlink.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/18 17:41:05 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/08 14:23:14 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstunlink(t_list **head, t_list *lst)
{
	t_list	*current;

	if (*head == lst)
	{
		*head = lst->next;
		lst->next = NULL;
		return (lst);
	}
	current = *head;
	while (current != NULL && current->next != lst)
		current = current->next;
	if (current == NULL)
		return (NULL);
	current->next = lst->next;
	lst->next = NULL;
	return (lst);
}
