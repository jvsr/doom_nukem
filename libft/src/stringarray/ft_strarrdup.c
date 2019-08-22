/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrdup.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:18:39 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:43:23 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringarray.h"

char	**ft_strarrdup(char **arr)
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
