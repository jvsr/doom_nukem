/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_float.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:20:02 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/10 22:34:55 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "error.h"
#include "serializer.h"

float		read_float(t_binary_read *bin_r)
{
	float f;

	if (bin_r->content_pos - bin_r->header_size + sizeof(float) >
		bin_r->file_size)
		error_msg("No space in file", 876, "Serializer");
	ft_memcpy(&f, bin_r->bytes + bin_r->content_pos, sizeof(float));
	bin_r->content_pos += sizeof(float);
	if (bin_r->endian == detect_endian())
		return (f);
	swap_bytes(&f, sizeof(f));
	return (f);
}
