/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_double.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:54:20 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 14:54:20 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"
#include "types.h"

double	read_double(unsigned char *bytes, t_endian endian)
{
	double d;

	ft_memcpy(&d, bytes, sizeof(double));
	if (endian == detect_endian())
		return (d);
	swap_bytes(&d, sizeof(d));
	return (d);
}
