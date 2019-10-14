/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_long.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:10:26 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 14:10:26 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"
#include "types.h"

long		read_long(unsigned char *bytes, t_endian endian)
{
	long l;

	ft_memcpy(&l, bytes, sizeof(l));
	if (endian == detect_endian())
		return (l);
	swap_bytes(&l, sizeof(l));
	return (l);
}
