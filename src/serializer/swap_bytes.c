/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_bytes.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 13:24:00 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/14 13:24:00 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	swap_bytes(void *v_bytes, size_t size)
{
	size_t	i;
	char	tmp;
	char	*bytes;

	i = 0;
	bytes = v_bytes;
	while (i < size / 2)
	{
		tmp = bytes[i];
		bytes[i] = bytes[size - 1 - i];
		bytes[size - 1 - i] = tmp;
		i++;
	}
}
