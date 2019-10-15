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

long		read_long(t_binary_read *bin_r)
{
	long l;

	ft_memcpy(&l, bin_r->bytes + bin_r->content_pos, sizeof(l));
	bin_r->content_pos += sizeof(l);
	if (bin_r->endian == detect_endian())
		return (l);
	swap_bytes(&l, sizeof(l));
	return (l);
}
