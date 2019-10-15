/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnumlst.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:40:55 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:11:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_str.h"
#include "ft_num.h"
#include "ft_char.h"

static t_bool	put_content(void *content, size_t size)
{
	if (size == sizeof(char))
		return (ft_putnum(*((char *)content)));
	else if (size == sizeof(short))
		return (ft_putnum(*((short *)content)));
	else if (size == sizeof(int))
		return (ft_putnum(*((int *)content)));
	else if (size == sizeof(long))
		return (ft_putnum(*((long *)content)));
	else
		return (ft_putnum(*((intmax_t *)content)));
	return (FALSE);
}

t_bool			ft_putnumlst(const t_list *lst)
{
	if (lst == NULL)
		return (ft_putstr(NULL));
	if (put_content(lst->content, lst->content_size) == FALSE)
		return (FALSE);
	if (ft_putchar('\n') == FALSE)
		return (FALSE);
	if (lst->next != NULL)
		return (ft_putnumlst(lst->next));
	return (TRUE);
}
