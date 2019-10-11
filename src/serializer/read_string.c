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

char	*read_string(unsigned char *header, unsigned char *bytes)
{
	long	size;
	char	*string;
	long	i;

	size = read_long(header + sizeof(long));
	string = ft_strnew(size);
	i = 0;
	while (i < size)
	{
		string[i] = *(bytes + i);
		i++;
	}
	return (string);
}
