/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_int.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:00:12 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/18 18:59:37 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"

int			read_int(t_binary_read *bin_r)
{
	int i;

	ft_memcpy(&i, bin_r->bytes + bin_r->content_pos, sizeof(int));
	bin_r->content_pos += sizeof(int);
	if (bin_r->endian == detect_endian())
		return (i);
	swap_bytes(&i, sizeof(i));
	return (i);
}
