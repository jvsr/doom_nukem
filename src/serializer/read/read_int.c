/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_int.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:00:12 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/10 22:34:50 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_printf.h"
#include "serializer.h"
#include "error.h"

int			read_int(t_binary_read *bin_r)
{
	int i;

	if (bin_r->content_pos - bin_r->header_size + sizeof(int) >
		bin_r->file_size)
		error_msg("No space in file", 876, "Serializer");
	ft_memcpy(&i, bin_r->bytes + bin_r->content_pos, sizeof(int));
	bin_r->content_pos += sizeof(int);
	if (bin_r->endian == detect_endian())
		return (i);
	swap_bytes(&i, sizeof(i));
	return (i);
}
