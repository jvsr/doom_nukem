/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrnew.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 18:29:21 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:40:16 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringarray.h"
#include "ft_memory.h"

char	**ft_strarrnew(size_t size)
{
	char	**arr;

	arr = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	return (arr);
}
