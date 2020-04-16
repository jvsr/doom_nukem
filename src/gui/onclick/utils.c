/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:44:40 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:46 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

void	incr_float_max(float *loc, float incr, float max)
{
	*loc += incr;
	if (*loc > max)
		*loc = max;
}

void	decr_float_min(float *loc, float decr, float min)
{
	*loc -= decr;
	if (*loc < min)
		*loc = min;
}

void	incr_uint16_max(t_uint16 *loc, t_uint16 incr, t_uint16 max)
{
	*loc += incr;
	if (*loc > max)
		*loc = max;
}

void	decr_uint16_min(t_uint16 *loc, t_uint16 decr, t_uint16 min)
{
	*loc -= decr;
	if (*loc < min)
		*loc = min;
}
