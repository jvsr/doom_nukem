/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlstsize.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:11:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_str.h"
#include "ft_num.h"
#include "ft_char.h"

t_bool	ft_putlstsize(const t_list *lst)
{
	if (lst == NULL)
		return (ft_putstr(NULL));
	if (ft_putnum(lst->content_size) == FALSE)
		return (FALSE);
	if (ft_putchar('\n') == FALSE)
		return (FALSE);
	if (lst->next != NULL)
		return (ft_putlstsize(lst->next));
	return (TRUE);
}
