/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrap_float.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:46:15 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/03 15:46:15 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

float	wrap_float(float f0, float min, float max)
{
	while (f0 < min)
		f0 = max - (fabs(min - f0));
	while (f0 > max)
		f0 = min + (fabs(max - f0));
	return (f0);
}
