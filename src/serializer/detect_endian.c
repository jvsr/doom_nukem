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
	unsigned int	i;
	unsigned char	*check;

	i = 1;
	check = (unsigned char*)&i;
	if (*check == 1)
		return (ENDIAN_LITTLE);
	return (ENDIAN_BIG);
}
