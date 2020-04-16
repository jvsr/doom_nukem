/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_short.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/08 11:02:44 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/10 22:35:11 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"
#include "error.h"

short		read_short(t_binary_read *bin_r)
{
	short s;

	if (bin_r->content_pos - bin_r->header_size + sizeof(short) >
		bin_r->file_size)
		error_msg("No space in file", 876, "Serializer");
	ft_memcpy(&s, bin_r->bytes + bin_r->content_pos, sizeof(s));
	bin_r->content_pos += sizeof(s);
	if (bin_r->endian == detect_endian())
		return (s);
	swap_bytes(&s, sizeof(s));
	return (s);
}
