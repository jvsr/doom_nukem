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

double	read_double(t_binary_read *bin_r)
{
	double d;

	ft_memcpy(&d, bin_r->bytes + bin_r->content_pos, sizeof(double));
	bin_r->content_pos += sizeof(double);
	if (bin_r->endian == detect_endian())
		return (d);
	swap_bytes(&d, sizeof(d));
	return (d);
}
