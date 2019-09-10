/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgba_to_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 13:47:23 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/10 14:58:04 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>
#include "types.h"

void	rgba_to_color(SDL_Color *c, t_uint32 color)
{
	c->a = (unsigned char)(color >> 24);
	c->r = (unsigned char)(color >> 16);
	c->g = (unsigned char)(color >> 8);
	c->b = (unsigned char)(color);
}
