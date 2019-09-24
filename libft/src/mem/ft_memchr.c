/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 20:17:24 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_types.h"

static void	*chr_32_last_8(const t_uint64 *str_8, t_uint8 temp_c, size_t index)
{
	return (ft_memchr(&str_8[index], temp_c, sizeof(t_uint64)));
}

static void	*chr_32(const t_uint64 *str_8, t_uint8 temp_c,
						size_t *i, size_t len)
{
	size_t			index;
	t_uint64		temp_c_8;
	const size_t	step = 4;
	const size_t	len_8 = len / sizeof(t_uint64);

	index = 0;
	ft_memset(&temp_c_8, temp_c, sizeof(temp_c_8));
	while ((index + step) < len_8)
	{
		if ((str_8[index] & temp_c_8) != 0)
			return (chr_32_last_8(str_8, temp_c, index));
		if ((str_8[index + 1] & temp_c_8) != 0)
			return (chr_32_last_8(str_8, temp_c, index + 1));
		if ((str_8[index + 2] & temp_c_8) != 0)
			return (chr_32_last_8(str_8, temp_c, index + 2));
		if ((str_8[index + 3] & temp_c_8) != 0)
			return (chr_32_last_8(str_8, temp_c, index + 3));
		index += step;
	}
	*i = index * sizeof(t_uint64);
	return (NULL);
}

void		*ft_memchr(const void *str, char c, size_t len)
{
	size_t			i;
	void			*found;
	const t_uint8	*temp_str;
	t_uint8			temp_c;

	i = 0;
	temp_c = c;
	temp_str = str;
	found = chr_32(str, temp_c, &i, len);
	if (found != NULL)
		return (found);
	while (i < len)
	{
		if (temp_str[i] == temp_c)
			return ((void *)&temp_str[i]);
		i++;
	}
	return (NULL);
}
