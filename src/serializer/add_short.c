/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_short.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 15:34:18 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/07 15:34:18 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

void		add_short(short s, t_binary *bin)
{
	t_convert con;

	con.s = s;
	add_type(&bin->content, &bin->c_size, &con, sizeof(s));
}
