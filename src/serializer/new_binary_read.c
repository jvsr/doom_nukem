/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_binary_read.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 16:17:39 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/14 16:17:39 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"
#include "error.h"

t_binary_read	*new_binary_read(const char *loc)
{
	t_binary_read	*bin_r;
	long			tmp;

	bin_r = (t_binary_read*)ft_memalloc(sizeof(t_binary_read));
	if (bin_r == NULL)
		error_msg_errno("Unable to allocate binary in-stream");
	bin_r->bytes = read_struct(loc);
	bin_r->header_pos = sizeof(long) + sizeof(char);
	ft_memcpy(&tmp, bin_r->bytes, sizeof(long));
	bin_r->content_pos = (size_t)tmp;
	bin_r->header_size = (size_t)tmp;
	bin_r->endian = (t_endian)((char)*(bin_r->bytes + sizeof(long)));
	return (bin_r);
}
