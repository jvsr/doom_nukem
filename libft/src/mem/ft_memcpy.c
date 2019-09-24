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

#include "ft_mem.h"
#include "ft_types.h"

static void	cpy_32(t_uint64 *dst_8, const t_uint64 *src_8,
					size_t *i, size_t len)
{
	size_t			index_step;
	const size_t	step = 4;
	const size_t	len_8 = len / sizeof(t_uint64);

	index_step = 0;
	while ((index_step + step) < len_8)
	{
		dst_8[index_step] = src_8[index_step];
		dst_8[index_step + 1] = src_8[index_step + 1];
		dst_8[index_step + 2] = src_8[index_step + 2];
		dst_8[index_step + 3] = src_8[index_step + 3];
		index_step += step;
	}
	*i = index_step * sizeof(t_uint64);
}

void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			i;
	t_uint8			*temp_dst;
	const t_uint8	*temp_src;

	cpy_32(dst, src, &i, len);
	temp_dst = dst;
	temp_src = src;
	while (i < len)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dst);
}
