/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 13:48:57 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/24 15:07:28 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"
#include "setting.h"

void	set_float(float setting, t_transform *location, int precision)
{
	set_elem_text_str(location,
		ft_strformat("%.*f", precision, setting));
}

void	set_int(int setting, t_transform *location)
{
	set_elem_text_str(location,
		ft_strformat("%d", setting));
}

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
