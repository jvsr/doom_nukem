/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgba_to_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 13:47:23 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 11:36:14 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

#include "types.h"

void	rgba_to_color(SDL_Color *c, t_uint32 rgba)
{
	c->a = (t_uint8)(rgba >> 24);
	c->r = (t_uint8)(rgba >> 16);
	c->g = (t_uint8)(rgba >> 8);
	c->b = (t_uint8)rgba;
}
