/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_headers.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 00:36:00 by pholster       #+#    #+#                */
/*   Updated: 2019/10/03 00:36:00 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "get_headers.h"

static size_t	len(const t_header *lst)
{
	size_t	len;

	len = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

static t_header	*index_lst(t_header *lst, size_t index)
{
	while (lst != NULL && index > 0)
	{
		lst = lst->next;
		index--;
	}
	return (lst);
}

static t_header	*join(t_header *head, t_header *half)
{
	if (head == NULL)
		return (half);
	if (half == NULL)
		return (head);
	if (strcmp(head->name, half->name) > 0)
	{
		half->next = join(head, half->next);
		return (half);
	}
	head->next = join(head->next, half);
	return (head);
}

void			sort_headers(t_header **head)
{
	t_header	*half;
	t_header	*temp;

	if ((*head)->next == NULL)
		return ;
	temp = index_lst(*head, (len(*head) - 1) / 2);
	half = temp->next;
	temp->next = NULL;
	sort_headers(head);
	sort_headers(&half);
	*head = join(*head, half);
}
