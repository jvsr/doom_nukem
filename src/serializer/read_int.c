/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_int.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:00:12 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 14:00:12 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

int			read_int(unsigned char *bytes)
{
	return ((int)*bytes | (int)*(bytes + 1) << 8 | (int)*(bytes + 2) << 16 |
		(int)*(bytes + 3) << 24);
}
