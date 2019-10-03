/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_extra.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 17:23:57 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/18 16:17:58 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_EXTRA_H
# define SDL_EXTRA_H

# include <SDL2/SDL_rect.h>
# include <SDL2/SDL_pixels.h>
# include <SDL2/SDL_surface.h>

# include "libft/ft_bool.h"
# include "types.h"

typedef struct s_circle	t_circle;

SDL_Surface	*sdl_create_surface_default(SDL_Point size);
void		sdl_clear_surface(SDL_Surface *surface);
void		sdl_fill_surface_color(SDL_Surface *surface, SDL_Color color);
void		sdl_draw_surface_circ(SDL_Surface *dst, SDL_Color color,
									t_circle c);
void		sdl_draw_surface_rect(SDL_Surface *dst, SDL_Color color,
									SDL_Rect rect);
void		sdl_draw_surface_rect_alpha(SDL_Surface *dst, SDL_Color color,
									SDL_Rect rect);
void		sdl_merge_surface(SDL_Surface *dst, SDL_Surface *src,
									SDL_Point start);
void		sdl_merge_surface_alpha(SDL_Surface *dst, SDL_Surface *src,
								SDL_Point start);
void		sdl_merge_surface_scaled(SDL_Surface *dst, SDL_Surface *src);
void		sdl_merge_surface_center(SDL_Surface *dst, SDL_Surface *src);
void		sdl_merge_surface_alpha_scaled(SDL_Surface *dst, SDL_Surface *src);
void		sdl_merge_surface_alpha_center(SDL_Surface *dst, SDL_Surface *src);
t_bool		sdl_has_surface_alpha(SDL_Surface *surface);
void		sdl_set_surface_alpha(SDL_Surface *surface, t_uint8 alpha);

#endif
