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

void		add_short(unsigned char **bytes, size_t *b_size, short s)
{
	t_convert con;

	con.s = s;
	add_type(bytes, b_size, &con, sizeof(s));
}
