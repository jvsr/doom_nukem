/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:48:45 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;

	srclen = 0;
	if (size == 0)
		return (ft_strlen(src));
	dstlen = ft_strnlen(dst, size);
	while (src[srclen] != '\0' && (dstlen + srclen) < (size - 1))
		srclen++;
	ft_memcpy(&dst[dstlen], src, srclen);
	if ((dstlen + srclen) != size)
		dst[(dstlen + srclen)] = '\0';
	return (dstlen + srclen + ft_strlen(&src[srclen]));
}
