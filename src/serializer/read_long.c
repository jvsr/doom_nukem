/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_long.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:10:26 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 14:10:26 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

long		read_long(unsigned char *bytes)
{
	return ((long)*bytes | (long)*(bytes + 1) << 8 | (long)*(bytes + 2) << 16 |
		(long)*(bytes + 3) << 24 | (long)*(bytes + 4) << 32 |
		(long)*(bytes + 5) << 40 | (long)*(bytes + 6) << 48 |
		(long)*(bytes + 7) << 56);
}
