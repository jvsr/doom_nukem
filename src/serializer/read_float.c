/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_float.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:20:02 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 14:20:02 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"

float		read_float(t_binary_read *bin_r)
{
	float f;

	ft_memcpy(&f, bin_r->bytes + bin_r->content_pos, sizeof(float));
	bin_r->content_pos += sizeof(float);
	if (bin_r->endian == detect_endian())
		return (f);
	swap_bytes(&f, sizeof(f));
	return (f);
}
