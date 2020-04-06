/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_between_fov.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 19:09:53 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:33:39 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"

t_bool	is_between_fov(float a, float start, float end)
{
	if (start < end)
		return (a >= start && a <= end);
	return ((a <= end && a >= 0) || (a >= start && a <= 360));
}
