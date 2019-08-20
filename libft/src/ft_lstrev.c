/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 13:15:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

void	ft_lstrev(t_list **head)
{
	t_list	*lst;
	t_list	*prvlst;
	t_list	*nxtlst;

	if (head == NULL || *head == NULL)
		return ;
	lst = *head;
	prvlst = NULL;
	while (lst != NULL)
	{
		nxtlst = lst->next;
		lst->next = prvlst;
		prvlst = lst;
		lst = nxtlst;
	}
	*head = prvlst;
}
