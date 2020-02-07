/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lerp.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 13:05:08 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/07 13:05:08 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmath.h"

float		lerp(float a, float b, float t)
{
	return (a + (b - a) * clamp_float(t, 0, 1));
}