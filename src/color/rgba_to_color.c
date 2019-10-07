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

void	rgba_to_color(SDL_Color *c, t_uint32 rgba)
{
	c->a = (unsigned char)(rgba >> 24);
	c->r = (unsigned char)(rgba >> 16);
	c->g = (unsigned char)(rgba >> 8);
	c->b = (unsigned char)(rgba);
}
