/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/14 14:56:10 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_memindex(const void *str, int c, size_t len)
{
	char	*ptr;

	ptr = ft_memchr(str, c, len);
	if (ptr == NULL)
		return (-1);
	return ((size_t)ptr - (size_t)str);
}
