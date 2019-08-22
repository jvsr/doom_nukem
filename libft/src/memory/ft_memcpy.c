/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:56:29 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:30 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memcpy(void *dst, void *src, size_t len)
{
	size_t			i;
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	i = 0;
	temp_dst = dst;
	temp_src = src;
	while (len - (i * 8) >= 8)
	{
		((long long *)temp_dst)[i] = ((long long *)temp_src)[i];
		i++;
	}
	i *= 8;
	while (i < len)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dst);
}
