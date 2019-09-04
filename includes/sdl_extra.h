/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_extra.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 17:23:57 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/04 15:18:22 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_EXTRA_H
# define SDL_EXTRA_H

#include <SDL2/SDL.h>

typedef struct s_color  t_color;
typedef struct s_pixel  t_pixel;
typedef struct s_circle t_circle;

void    sdl_surface_draw_rect(SDL_Surface *dst, t_color color, SDL_Rect rect);
void    sdl_surface_draw_rect_alpha(SDL_Surface *dst, t_color color, SDL_Rect rect);
void	sdl_surface_merge(SDL_Surface *dst, SDL_Surface *src, t_pixel start);
void	sdl_surface_merge_alpha(SDL_Surface *dst, SDL_Surface *src, t_pixel start);
void	sdl_surface_draw_circ(SDL_Surface *dst, t_color color, t_circle c);

#endif
