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

#include "ft_mem.h"
#include "ft_types.h"

static void	cpy_32(t_uint64 *dst_8, const t_uint64 *src_8, size_t *len)
{
	size_t			steps_taken;
	size_t			index;
	const size_t	step = 4;

	steps_taken = 0;
	index = *len / sizeof(t_uint64);
	while (index >= step)
	{
		dst_8[index - 1] = src_8[index - 1];
		dst_8[index - 2] = src_8[index - 2];
		dst_8[index - 3] = src_8[index - 3];
		dst_8[index - 4] = src_8[index - 4];
		index -= step;
		steps_taken++;
	}
	*len -= steps_taken * (sizeof(t_uint64) * step);
}

void		*ft_memrcpy(void *dst, const void *src, size_t len)
{
	t_uint8			*temp_dst;
	const t_uint8	*temp_src;

	temp_dst = dst;
	temp_src = src;
	if (len >= 32)
		cpy_32(dst, src, &len);
	while (len > 0)
	{
		len--;
		temp_dst[len] = temp_src[len];
	}
	return (dst);
}
