/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finish_bin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 15:18:28 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 15:18:28 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "serializer.h"

void		finish_bin(t_binary *bin)
{
	long			l;
	unsigned char	*arg;
	unsigned char	type;

	type = (unsigned char)detect_endian();
	l = (long)bin->h_size;
	l += sizeof(l) + sizeof(type);
	arg = ft_memalloc(sizeof(l) + sizeof(type) + bin->h_size + bin->c_size);
	ft_memcpy(arg, &l, sizeof(l));
	ft_memcpy(arg + sizeof(l), &type, sizeof(type));
	ft_memcpy(arg + sizeof(l) + sizeof(type), bin->header, bin->h_size);
	ft_memcpy(arg + l, bin->content, bin->c_size);
	ft_memdel((void**)&(bin->content));
	bin->content = arg;
	bin->c_size += l;
}
