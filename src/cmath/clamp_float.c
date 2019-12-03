/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clamp_float.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 15:19:05 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/03 15:19:05 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

float		clamp_float(float f0, float min, float max)
{
	if (f0 < min)
		return (min);
	else if (f0 > max)
		return (max);
	return (f0);	
}