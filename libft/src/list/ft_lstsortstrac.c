/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsortstrac.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/15 17:28:11 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:10:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

t_bool		ft_lstsortstrac(const t_list *sortlst, const t_list *lst)
{
	int		result;
	size_t	n;

	n = sortlst->content_size;
	if (n < lst->content_size)
		n = lst->content_size;
	result = ft_memcmp(sortlst->content, lst->content, n);
	return (result > 0 && result != 0);
}
