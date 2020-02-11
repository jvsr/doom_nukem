/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lerp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 13:05:08 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/10 17:54:22 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmath.h"

float		lerp(float a, float b, float t)
{
	return (a + (b - a) * clamp_float(t, 0, 1));
}

float		lerp_max(float a, float b, float t, float max)
{
	return (a + (b - a) * clamp_float(t, 0, max));
}
