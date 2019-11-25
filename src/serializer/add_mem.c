/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_mem.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 15:05:43 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 15:05:43 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "serializer.h"

void		add_mem(void *mem, t_uint64 size, t_binary *bin)
{
	t_uint64		i;
	t_convert		con;
	t_uint8	const	*stream = mem;

	con.l = bin->c_size;
	add_type(&bin->header, &bin->h_size, &con, sizeof(t_uint64));
	con.l = size;
	add_type(&bin->header, &bin->h_size, &con, sizeof(t_uint64));
	i = 0;
	while (i < size)
	{
		add_char(stream[i], bin);
		i++;
	}
}
