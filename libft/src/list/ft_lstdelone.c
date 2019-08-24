/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 18:26:53 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 17:08:17 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **head, void (*del)(void *, size_t))
{
	if (head == NULL || *head == NULL)
		return ;
	if (del != NULL && (*head)->content != NULL)
		del((*head)->content, (*head)->content_size);
	free(*head);
	*head = NULL;
}
