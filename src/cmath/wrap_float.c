/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrap_float.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:46:15 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:33:10 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

float	wrap_float(float f0, float min, float max)
{
	if (f0 < min)
		return (wrap_float(max + (f0 - min), min, max));
	if (f0 >= max)
		return (wrap_float((f0 + min) - max, min, max));
	return (f0);
}
