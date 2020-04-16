/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_header.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:56:55 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/10 22:30:26 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"
#include "error.h"

long		read_header(t_binary_read *bin_r)
{
	long l;

	if (bin_r->header_pos + sizeof(long) > bin_r->header_size)
		error_msg("No space in file", 876, "Serializer");
	l = *(bin_r->bytes + bin_r->header_pos);
	bin_r->header_pos += sizeof(long);
	if (bin_r->endian != detect_endian())
		swap_bytes(&l, sizeof(l));
	return (l);
}
