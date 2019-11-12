/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mix_color.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/14 18:53:49 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/09 19:26:58 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

#include "color.h"

t_uint32	mix_color(t_uint32 dst, t_uint32 src)
{
	float		op;
	SDL_Color	cdst;
	SDL_Color	csrc;
	const int	maxalpha = 255;

	rgba_to_color(&cdst, dst);
	rgba_to_color(&csrc, src);
	op = (float)csrc.a / maxalpha;
	cdst.a -= (cdst.a - csrc.a) * ((float)csrc.a / maxalpha);
	cdst.r = cdst.r * (1 - op) + csrc.r * op;
	cdst.g = cdst.g * (1 - op) + csrc.g * op;
	cdst.b = cdst.b * (1 - op) + csrc.b * op;
	return (color_to_rgba(cdst));
}
