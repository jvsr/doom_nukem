/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_float.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:20:02 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 14:20:02 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

float		read_float(unsigned char *bytes)
{
	float f;

	ft_memcpy(&f, bytes, sizeof(float));
	return (f);
}
