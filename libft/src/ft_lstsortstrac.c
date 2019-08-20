/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsortstrac.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:28:11 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_lstsortstrac(t_list *sortlst, t_list *lst)
{
	int		result;
	size_t	n;

	n = sortlst->content_size;
	if (n < lst->content_size)
		n = lst->content_size;
	result = ft_memcmp(sortlst->content, lst->content, n);
	return (result > 0 && result != 0);
}
