/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_short.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/08 11:02:44 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/08 11:02:44 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

short		read_short(unsigned char *bytes)
{
	return ((short)*bytes | (short)*(bytes + 1) << 8);
}
