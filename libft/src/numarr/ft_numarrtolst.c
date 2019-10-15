/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_numarrtolst.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 10:14:45 by pholster       #+#    #+#                */
/*   Updated: 2019/08/23 15:57:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_numarr.h"
#include "ft_num.h"
#include "ft_list.h"

static t_list	*freeret(t_list **lst)
{
	ft_lstdel(lst, &ft_lstdelmem);
	return (NULL);
}

t_list			*ft_numarrtolst(const intmax_t *arr, size_t len)
{
	t_list		*returnlst;
	t_list		*prvlst;
	t_list		*newlst;
	intmax_t	num;
	size_t		i;

	i = 0;
	num = arr[i];
	returnlst = ft_lstnew_dup(&num, sizeof(intmax_t));
	if (returnlst == NULL)
		return (NULL);
	prvlst = returnlst;
	while (i < len)
	{
		i++;
		num = arr[i];
		newlst = ft_lstnew_dup(&num, sizeof(intmax_t));
		if (newlst == NULL)
			return (freeret(&returnlst));
		prvlst->next = newlst;
		prvlst = returnlst;
	}
	return (returnlst);
}
