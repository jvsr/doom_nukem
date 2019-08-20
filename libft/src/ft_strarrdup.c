/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrdup.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:18:39 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrdup(const char **arr)
{
	char	**dup;

	dup = ft_strarrnew(ft_strarrlen(arr));
	if (dup == NULL)
		return (NULL);
	if (ft_strarrcpy(dup, arr) == NULL)
	{
		ft_strarrdel(&dup);
		return (NULL);
	}
	return (dup);
}
