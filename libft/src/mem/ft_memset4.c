/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset4.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 16:08:38 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:13:07 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_types.h"

static t_uint64	prepare_8(t_uint64 c)
{
	t_uint64	temp_c;

	temp_c = (c << 0);
	temp_c |= (c << 32);
	return (temp_c);
}

static void		set_32(t_uint64 *str_8, t_uint64 c_8, size_t *i, size_t len)
{
	size_t			index_step;
	const size_t	step = 4;
	const size_t	len_8 = len / sizeof(t_uint16);

	index_step = 0;
	while ((index_step + step) < len_8)
	{
		str_8[index_step] = c_8;
		str_8[index_step + 1] = c_8;
		str_8[index_step + 2] = c_8;
		str_8[index_step + 3] = c_8;
		index_step += step;
	}
	*i = index_step * sizeof(t_uint16);
}

void			*ft_memset4(void *str, int c, size_t len)
{
	size_t		i;
	t_uint32	temp_c;
	t_uint32	*temp_str;

	temp_c = c;
	set_32(str, prepare_8(temp_c), &i, len);
	temp_str = str;
	while (i < len)
	{
		temp_str[i] = temp_c;
		i++;
	}
	return (str);
}
