/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_double.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:54:20 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/11 14:54:20 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

double	read_double(unsigned char *bytes)
{
	double d;

	ft_memcpy(&d, bytes, sizeof(double));
	return (d);
}
