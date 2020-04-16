/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_vfov.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 11:53:17 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:34:43 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "setting.h"
#include "cmath.h"

float	calc_vfov(float fov, float width, float height)
{
	float const h_fov = tan((fov * PI_R) / 2.0);
	float const ratio = height / width;

	return (ceil(2.0 * atan(h_fov * ratio) * PI_D));
}
