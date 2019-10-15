/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_long.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 15:36:46 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/07 15:36:46 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

void		add_long(long l, t_binary *bin)
{
	t_convert con;

	con.l = l;
	add_type(&bin->content, &bin->c_size, &con, sizeof(l));
}
