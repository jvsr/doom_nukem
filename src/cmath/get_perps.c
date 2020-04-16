/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_perps.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 13:23:22 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:34:01 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "coord.h"
#include "cmath.h"

t_coord		get_perps(float angle)
{
	t_coord	perps;

	perps.x = wrap_float(angle + 90, 0, 360);
	perps.y = wrap_float(angle - 90, 0, 360);
	return (perps);
}
