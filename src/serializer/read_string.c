/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_string.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 16:19:05 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 16:19:05 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"
#include "serializer.h"
#include "error.h"

char	*read_string(t_binary_read *bin_r)
{
	long	size;
	char	*string;
	long	i;

	bin_r->header_pos += sizeof(long);
	size = read_header(bin_r);
	string = ft_strnew(size);
	if (string == NULL)
		error_msg_errno("Unable to allocate string");
	i = 0;
	while (i < size)
	{
		string[i] = *(bin_r->bytes + bin_r->content_pos + i);
		i++;
	}
	bin_r->content_pos += sizeof(char) * size;
	return (string);
}
