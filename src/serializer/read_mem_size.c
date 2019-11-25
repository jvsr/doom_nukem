/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_mem_size.c                                    :+:    :+:            */
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

void	*read_mem_size(size_t size, t_binary_read *bin_r)
{
	void	*mem;

	mem = ft_memalloc(size);
	if (mem == NULL)
		error_msg_errno("Unable to allocate memory for read");
	ft_memcpy(mem, bin_r->bytes + bin_r->content_pos, size);
	bin_r->content_pos += size;
	return (mem);
}
