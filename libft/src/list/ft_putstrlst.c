/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrlst.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:11:52 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

t_bool	ft_putstrlst(const t_list *lst)
{
	if (lst == NULL)
		return (ft_putstr(NULL));
	if (ft_putendl((char *)lst->content) == FALSE)
		return (FALSE);
	if (lst->next != NULL)
		return (ft_putstrlst(lst->next));
	return (FALSE);
}
