/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_text.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 17:27:05 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 10:44:35 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>

#include "libft/ft_character.h"
#include "libft/ft_string.h"

#include "gui.h"
#include "sdl_extra.h"
#include "error.h"

static t_bool		is_empty_str(const char *str)
{
	return (str[ft_strislen(str, &ft_isspace)] == '\0');
}

static SDL_Surface	*render_text(const char *str, TTF_Font *font,
								SDL_Color *color)
{
	SDL_Surface	*text;
	SDL_Surface	*formatted;

	text = TTF_RenderText_Shaded(font, str, *color, (SDL_Color){0, 0, 0, 0});
	if (text == NULL)
		error_msg(SDL_GetError(), 1, "Failed to render text");
	formatted = SDL_ConvertSurfaceFormat(text, SDL_PIXELFORMAT_RGBA32, 0);
	if (formatted == NULL)
		error_msg(SDL_GetError(), 1, "Failed to format text");
	SDL_FreeSurface(text);
	return (formatted);
}

static SDL_Surface	*scale_text(SDL_Surface *text, float size)
{
	const SDL_Point	scaled_size = {text->w * size, text->h * size};
	SDL_Surface		*scaled;

	scaled = sdl_create_surface_default(scaled_size);
	sdl_merge_surface_alpha_scaled(scaled, text);
	return (scaled);
}

void				draw_text(SDL_Surface *dst, t_text *text)
{
	TTF_Font	*font;
	SDL_Surface	*rendered_text;
	SDL_Surface	*scaled_text;

	if (text->str == NULL || is_empty_str(text->str))
		return ;
	font = get_font(text->fonts, text->font_type);
	rendered_text = render_text(text->str, font, &text->color);
	if (text->draw_method == SCALED)
		sdl_merge_surface_alpha_scaled(dst, rendered_text);
	else
	{
		scaled_text = scale_text(rendered_text, text->size);
		sdl_fill_surface_color(dst, text->bg_color);
		if (text->draw_method == FIXED)
			sdl_merge_surface(dst, scaled_text, (SDL_Point){0, 0});
		else if (text->draw_method == CENTERED)
			sdl_merge_surface_center(dst, scaled_text);
		SDL_FreeSurface(scaled_text);
	}
	SDL_FreeSurface(rendered_text);
}
