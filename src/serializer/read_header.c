/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_header.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:56:55 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/14 16:56:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

long		read_header(t_binary_read *bin_r)
{
	long l;

	l = *(bin_r->bytes + bin_r->header_pos);
	bin_r->header_pos += sizeof(long);
	if (bin_r->endian != detect_endian())
		swap_bytes(&l, sizeof(l));
	return (l);
}
