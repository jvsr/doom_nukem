/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_between_or_equal.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/30 18:14:43 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:33:33 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "coord.h"

t_bool		is_between_or_equal(float a, float x, float y)
{
	return ((a >= x && a <= y) || (a <= x && a >= y));
}
