/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnumlst.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_putnumlst(t_list *lst)
{
	intmax_t	*n;

	if (lst == NULL)
		return (TRUE);
	n = (intmax_t *)lst->content;
	if (ft_putnum(*n) == FALSE)
		return (FALSE);
	if (ft_putchar('\n') == FALSE)
		return (FALSE);
	if (lst->next != NULL)
		return (ft_putnumlst(lst->next));
	return (TRUE);
}
