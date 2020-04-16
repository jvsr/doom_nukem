/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_between.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/20 16:42:28 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:33:28 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "coord.h"

t_bool		is_between(float a, float x, float y)
{
	return ((a > x && a < y) || (a < x && a > y));
}
