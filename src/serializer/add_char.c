/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_char.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 15:31:58 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/07 15:31:58 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

void		add_char(char c, t_binary *bin)
{
	t_convert con;

	con.c = c;
	add_type(&bin->content, &bin->c_size, &con, sizeof(c));
}