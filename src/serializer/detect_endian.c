/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   detect_endian.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 10:33:31 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/14 10:33:31 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_endian		detect_endian(void)
{
	const int	i = 1;

	if (*((unsigned char*)&i) == 1)
		return (ENDIAN_LITTLE);
	return (ENDIAN_BIG);
}
