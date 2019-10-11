/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_string.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 15:05:43 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 15:05:43 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "serializer.h"

void		add_string(char *string, t_binary *bin)
{
	size_t		s_size;
	size_t		i;
	t_convert	con;

	s_size = ft_strlen(string);
	con.l = (long)bin->c_size;
	add_type(&bin->header, &bin->h_size, &con, sizeof(long));
	con.l = (long)s_size;
	add_type(&bin->header, &bin->h_size, &con, sizeof(long));
	i = 0;
	while (i < s_size)
	{
		add_char(string[i], bin);
		i++;
	}
}
