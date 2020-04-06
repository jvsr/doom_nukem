/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wrap_angle.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 15:00:33 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:33:13 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cmath.h"

float	wrap_angle(float angle)
{
	return (wrap_float(angle, 0, 360));
}
