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

void		add_float(unsigned char **bytes, size_t *b_size, float f)
{
	t_convert con;

	con.f = f;
	add_type(bytes, b_size, &con, sizeof(f));
}
