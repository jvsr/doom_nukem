/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 13:57:08 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:37:54 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)ft_memalloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}
