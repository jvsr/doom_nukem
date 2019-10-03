/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:24:25 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

static size_t	c_pos(const void *src, void *found)
{
	size_t	found_addr;
	size_t	src_addr;

	found_addr = (size_t)found;
	src_addr = (size_t)src;
	if (src_addr < found_addr)
		return (found_addr - src_addr);
	return (src_addr - found_addr);
}

void			*ft_memccpy(void *dst, const void *src, char c, size_t len)
{
	char	*found;
	size_t	found_pos;

	found = (char *)ft_memchr(src, c, len);
	if (found == NULL)
		found_pos = len;
	else
	{
		found_pos = c_pos(src, found);
		found++;
	}
	ft_memcpy(dst, src, found_pos);
	return (found);
}
