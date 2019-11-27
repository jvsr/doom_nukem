/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_vfov.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 11:53:17 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/27 11:53:17 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "setting.h"
#include "cmath.h"

void	calc_vfov(t_setting *set, float width, float height)
{
	float const h_fov = tan((set->fov * PI_D) / 2);
	float const ratio = width / height;

	set->vfov = ceil(2 * atan(h_fov * ratio) * PI_D);
}
