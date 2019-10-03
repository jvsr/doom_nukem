/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 20:17:24 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_types.h"

static void	*rchr_32_last_8(const t_uint64 *str_8, t_uint8 temp_c, size_t index)
{
	return (ft_memrchr(&str_8[index], temp_c, sizeof(t_uint64)));
}

static void	*rchr_32(const t_uint64 *str_8, t_uint8 temp_c, size_t *len)
{
	size_t			steps_taken;
	size_t			index;
	t_uint64		temp_c_8;
	const size_t	step = 4;

	steps_taken = 0;
	ft_memset(&temp_c_8, temp_c, sizeof(temp_c_8));
	index = *len / sizeof(t_uint64);
	while (index >= step)
	{
		if ((str_8[index - 1] & temp_c_8) != 0)
			return (rchr_32_last_8(str_8, temp_c, index - 1));
		if ((str_8[index - 2] & temp_c_8) != 0)
			return (rchr_32_last_8(str_8, temp_c, index - 2));
		if ((str_8[index - 3] & temp_c_8) != 0)
			return (rchr_32_last_8(str_8, temp_c, index - 3));
		if ((str_8[index - 4] & temp_c_8) != 0)
			return (rchr_32_last_8(str_8, temp_c, index - 4));
		index -= step;
		steps_taken++;
	}
	*len -= steps_taken * (sizeof(t_uint64) * step);
	return (NULL);
}

void		*ft_memrchr(const void *str, char c, size_t len)
{
	void			*found;
	const t_uint8	*temp_str;
	t_uint8			temp_c;

	temp_c = c;
	temp_str = str;
	if (len >= 32)
	{
		found = rchr_32(str, temp_c, &len);
		if (found != NULL)
			return (found);
	}
	while (len > 0)
	{
		len--;
		if (temp_str[len] == temp_c)
			return ((void *)&temp_str[len]);
	}
	return (NULL);
}
