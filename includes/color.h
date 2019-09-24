/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 17:00:37 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/10 14:56:50 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <SDL2/SDL_pixels.h>

# include "types.h"

t_uint32	color_to_rgba(SDL_Color c);
void		rgba_to_color(SDL_Color *c, t_uint32 color);

#endif
