/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_short.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/08 11:02:44 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/08 11:02:44 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"

short		read_short(t_binary_read *bin_r)
{
	short s;

	ft_memcpy(&s, bin_r->bytes + bin_r->content_pos, sizeof(s));
	bin_r->content_pos += sizeof(s);
	if (bin_r->endian == detect_endian())
		return (s);
	swap_bytes(&s, sizeof(s));
	return (s);
}
