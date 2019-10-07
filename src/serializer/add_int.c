/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_int.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 15:26:45 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/07 15:26:45 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

void	add_int(unsigned char **bytes, size_t *b_size, int i)
{
	t_convert con;

	con.i = i;
	add_type(bytes, b_size, &con, sizeof(i));
}
