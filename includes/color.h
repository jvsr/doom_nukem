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

# include "libft/ft_bool.h"

# include "types.h"

t_uint32	color_to_rgba(SDL_Color c);
char		*color_to_hex(SDL_Color c, t_bool include_alpha);
void		rgba_to_color(SDL_Color *c, t_uint32 rgba);
void		hex_to_color(SDL_Color *c, char *hex);
t_uint32	mix_color(t_uint32 dst, t_uint32 src);

#endif
