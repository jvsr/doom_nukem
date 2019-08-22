/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_normalize.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:42:00 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:15:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_number.h"

float	ft_normalize(intmax_t value, intmax_t *range, intmax_t *outrange)
{
	intmax_t	rangemin;
	intmax_t	rangemax;
	intmax_t	outrangemin;
	intmax_t	outrangemax;
	float		out;

	rangemin = range[0];
	rangemax = range[1];
	outrangemin = outrange[0];
	outrangemax = outrange[1];
	out = (float)(outrangemax - outrangemin) / (rangemax - rangemin);
	out *= outrangemin + (value - rangemin);
	return (out);
}
