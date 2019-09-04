/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:56:29 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:13:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

/*
** make it use 8 by 8 long long cpy
*/

void	*ft_memrcpy(void *dst, const void *src, size_t len)
{
	const unsigned char	*temp_src;
	unsigned char		*temp_dst;

	temp_dst = dst;
	temp_src = src;
	while (len > 0)
	{
		len--;
		temp_dst[len] = temp_src[len];
	}
	return (dst);
}
