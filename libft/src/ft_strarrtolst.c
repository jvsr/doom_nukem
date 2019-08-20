/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrtolst.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 14:48:15 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*freeret(t_list **lst)
{
	ft_lstdel(lst, &ft_lstdelmem);
	return (NULL);
}

t_list			*ft_strarrtolst(const char **arr)
{
	size_t	i;
	t_list	*newlst;
	t_list	*prvlst;
	t_list	*returnlst;

	i = 0;
	if (arr == NULL)
		return (NULL);
	returnlst = ft_lstnew(arr[i], ft_strlen(arr[i]) + 1);
	if (returnlst == NULL)
		return (NULL);
	prvlst = returnlst;
	i++;
	while (arr[i] != 0)
	{
		newlst = ft_lstnew(arr[i], ft_strlen(arr[i]) + 1);
		if (newlst == NULL)
			return (freeret(&returnlst));
		prvlst->next = newlst;
		prvlst = newlst;
		i++;
	}
	return (returnlst);
}
