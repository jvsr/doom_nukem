/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_long.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:10:26 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/10 22:34:53 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "error.h"
#include "serializer.h"

long		read_long(t_binary_read *bin_r)
{
	long l;

	if (bin_r->content_pos - bin_r->header_size + sizeof(long) >
		bin_r->file_size)
		error_msg("No space in file", 876, "Serializer");
	ft_memcpy(&l, bin_r->bytes + bin_r->content_pos, sizeof(l));
	bin_r->content_pos += sizeof(l);
	if (bin_r->endian == detect_endian())
		return (l);
	swap_bytes(&l, sizeof(l));
	return (l);
}
