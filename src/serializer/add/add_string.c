/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_string.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 15:05:43 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:55:13 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "serializer.h"

void		add_string(char *string, t_binary *bin)
{
	t_uint64	s_size;
	t_uint64	i;
	t_convert	con;

	s_size = ft_strlen(string);
	con.l = bin->c_size;
	add_type(&bin->header, &bin->h_size, &con, sizeof(t_uint64));
	con.l = s_size;
	add_type(&bin->header, &bin->h_size, &con, sizeof(t_uint64));
	i = 0;
	while (i < s_size)
	{
		add_char(string[i], bin);
		i++;
	}
}
