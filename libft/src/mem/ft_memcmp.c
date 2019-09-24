/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:53:02 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_types.h"

static int	cmp_8(const t_uint8 *str1, const t_uint8 *str2,
						size_t *index, size_t len)
{
	const size_t	step = 8;

	while ((*index + step) < len)
	{
		if (str1[*index] != str2[*index])
			return (str1[*index] - str2[*index]);
		if (str1[*index + 1] != str2[*index + 1])
			return (str1[*index + 1] - str2[*index + 1]);
		if (str1[*index + 2] != str2[*index + 2])
			return (str1[*index + 2] - str2[*index + 2]);
		if (str1[*index + 3] != str2[*index + 3])
			return (str1[*index + 3] - str2[*index + 3]);
		if (str1[*index + 4] != str2[*index + 4])
			return (str1[*index + 4] - str2[*index + 4]);
		if (str1[*index + 5] != str2[*index + 5])
			return (str1[*index + 5] - str2[*index + 5]);
		if (str1[*index + 6] != str2[*index + 6])
			return (str1[*index + 6] - str2[*index + 6]);
		if (str1[*index + 7] != str2[*index + 7])
			return (str1[*index + 7] - str2[*index + 7]);
		*index += step;
	}
	return (0);
}

int			ft_memcmp(const void *str1, const void *str2, size_t len)
{
	size_t			i;
	int				found;
	const t_uint8	*temp_str1;
	const t_uint8	*temp_str2;

	i = 0;
	temp_str1 = str1;
	temp_str2 = str2;
	found = cmp_8(str1, str2, &i, len);
	if (found != 0)
		return (found);
	while (i < len)
	{
		if (temp_str1[i] != temp_str2[i])
			return (temp_str1[i] - temp_str2[i]);
		i++;
	}
	return (0);
}
