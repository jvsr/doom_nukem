/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgba_to_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 13:47:23 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 13:41:21 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

void	rgba_to_color(SDL_Color *c, uint32_t color)
{
	c->a = (unsigned char)(color >> 24);
	c->r = (unsigned char)(color >> 16);
	c->g = (unsigned char)(color >> 8);
	c->b = (unsigned char)(color);
}
