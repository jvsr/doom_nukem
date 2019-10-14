/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_short.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/08 11:02:44 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/08 11:02:44 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"
#include "types.h"

short		read_short(unsigned char *bytes, t_endian endian)
{
	short s;

	ft_memcpy(&s, bytes, sizeof(s));
	if (endian == detect_endian())
		return (s);
	swap_bytes(&s, sizeof(s));
	return (s);
}
