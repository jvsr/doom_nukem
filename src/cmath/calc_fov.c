/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_fov.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/24 13:51:53 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:33:08 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

float		calc_fov(float a, float b)
{
	if (a < b)
		return (b - a);
	else if (a == b)
		return (0);
	return (b + (360 - a));
}
