/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_mem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:19:05 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 16:19:05 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "serializer.h"
#include "error.h"

void	*read_mem(t_binary_read *bin_r)
{
	size_t	size;

	bin_r->header_pos += sizeof(long);
	size = read_header(bin_r);
	return (read_mem_size(size, bin_r));
}
