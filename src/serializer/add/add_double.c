/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_double.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 15:39:43 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:56:35 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

void		add_double(double d, t_binary *bin)
{
	t_convert con;

	con.d = d;
	add_type(&bin->content, &bin->c_size, &con, sizeof(d));
}
