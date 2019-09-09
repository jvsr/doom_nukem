/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 17:00:37 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 15:18:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <SDL2/SDL_pixels.h>
# include <_types/_uint32_t.h>

uint32_t	color_to_rgba(SDL_Color c);
void		rgba_to_color(SDL_Color *c, Uint32 color);

#endif
