/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_int.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:00:12 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 14:00:12 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"
#include "types.h"

int			read_int(unsigned char *bytes, t_endian endian)
{
	int i;

	ft_memcpy(&i, bytes, sizeof(int));
	if (endian == detect_endian())
		return (i);
	swap_bytes(&i, sizeof(i));
	return (i);
}
