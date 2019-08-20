/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstrlst.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_putstrlst(t_list *lst)
{
	if (lst == NULL)
		return (TRUE);
	if (ft_putendl((char *)lst->content) == FALSE)
		return (FALSE);
	if (lst->next != NULL)
		return (ft_putstrlst(lst->next));
	return (FALSE);
}
