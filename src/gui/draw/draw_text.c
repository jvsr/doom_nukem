/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_text.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 17:27:05 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/24 15:19:30 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>

#include "libft/ft_str.h"

#include "gui_internal.h"
#include "sdl_extra.h"
#include "error.h"

/*
** * Gui internal function
*/

static SDL_Surface	*scale_text(SDL_Surface *text, float size)
{
	const SDL_Point	scaled_size = {text->w * size, text->h * size};
	SDL_Surface		*scaled;

	scaled = sdl_create_surface_default(scaled_size);
	sdl_merge_surface_scaled(scaled, text);
	return (scaled);
}

static void			merge_text(SDL_Surface *dst, t_text *text,
								SDL_Surface *rendered_text)
{
	SDL_Surface	*scaled_text;

	scaled_text = scale_text(rendered_text, text->size);
	if (text->draw_method == FIXED)
		sdl_merge_surface_alpha(dst, scaled_text, (SDL_Point){0, 0});
	else if (text->draw_method == CENTERED)
		sdl_merge_surface_alpha_center(dst, scaled_text);
	else if (text->draw_method == REPEAT)
		sdl_merge_surface_alpha_repeat(dst, scaled_text);
	SDL_FreeSurface(scaled_text);
}

void				draw_text(SDL_Surface *dst, t_text *text)
{
	TTF_Font	*font;
	SDL_Surface	*rendered_text;

	if (text->color.a == 0 || text->text == NULL || ft_strisempty(text->text))
		return ;
	font = text->fonts[text->font_type];
	rendered_text = render_text(text->text, font, &text->color);
	if (text->draw_method != SCALED)
		merge_text(dst, text, rendered_text);
	else
		sdl_merge_surface_alpha_scaled(dst, rendered_text);
	SDL_FreeSurface(rendered_text);
}
