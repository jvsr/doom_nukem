/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_float.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 15:38:13 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/07 15:38:13 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

void		add_float(float f, t_binary *bin)
{
	t_convert con;

	con.f = f;
	add_type(&bin->content, &bin->c_size, &con, sizeof(f));
}
