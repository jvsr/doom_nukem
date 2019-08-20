/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstinsert.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/16 22:50:52 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list *head, t_list *lst)
{
	t_list	*lstlast;

	if (head == NULL || lst == NULL)
		return ;
	lstlast = ft_lstlast(lst);
	lstlast->next = head->next;
	head->next = lst;
}
