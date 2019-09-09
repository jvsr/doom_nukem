/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_extra.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 17:23:57 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 16:44:19 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_EXTRA_H
# define SDL_EXTRA_H

# include <SDL2/SDL_rect.h>
# include <SDL2/SDL_pixels.h>
# include <SDL2/SDL_surface.h>

typedef struct s_circle	t_circle;

void	sdl_draw_surface_circ(SDL_Surface *dst, SDL_Color color, t_circle c);
void	sdl_draw_surface_rect(SDL_Surface *dst, SDL_Color color, SDL_Rect rect);
void	sdl_draw_surface_rect_alpha(SDL_Surface *dst, SDL_Color color,
									SDL_Rect rect);
void	sdl_merge_surface(SDL_Surface *dst, SDL_Surface *src, SDL_Point start);
void	sdl_merge_surface_alpha(SDL_Surface *dst, SDL_Surface *src,
								SDL_Point start);

#endif
