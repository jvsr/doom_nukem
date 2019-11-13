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

#include <math.h>
#include <SDL2/SDL_rect.h>

#include "libft/ft_str.h"

#include "gui_internal.h"
#include "sdl_extra.h"
#include "error.h"

/*
** * Gui internal function
*/

static void			get_smaller_scale(SDL_Point *text_size,
								SDL_Point scaled_width, SDL_Point scaled_height)
{
	int	scaled_width_sum;
	int	scaled_height_sum;

	scaled_width_sum = (scaled_width.x + scaled_width.y);
	scaled_height_sum = (scaled_height.x + scaled_height.y);
	if (scaled_width_sum < scaled_height_sum)
		*text_size = scaled_width;
	else
		*text_size = scaled_height;
}

static void			get_scaled_text_size(SDL_Point abs_dim, t_coord text_ratio,
							SDL_Point *scaled_width, SDL_Point *scaled_height)
{
	scaled_width->x = abs_dim.x;
	scaled_width->y = (int)round(abs_dim.x * text_ratio.y);
	scaled_height->x = (int)round(abs_dim.y * text_ratio.x);
	scaled_height->y = abs_dim.y;
}

static SDL_Surface	*scale_text(SDL_Surface *text, float size,
								SDL_Point abs_dim)
{
	SDL_Surface	*scaled;
	SDL_Point	text_size;
	SDL_Point	scaled_width;
	SDL_Point	scaled_height;
	t_coord		text_ratio;

	text_ratio = (t_coord){(float)text->w / text->h, (float)text->h / text->w};
	get_scaled_text_size(abs_dim, text_ratio, &scaled_width, &scaled_height);
	get_smaller_scale(&text_size, scaled_width, scaled_height);
	text_size.x *= size;
	text_size.y *= size;
	scaled = sdl_create_surface_default(text_size);
	sdl_merge_surface_scaled(scaled, text);
	return (scaled);
}

static void			merge_text(SDL_Surface *dst, t_text *text,
								SDL_Surface *scaled_text)
{
	if (text->draw_method == FIXED)
		sdl_merge_surface_alpha(dst, scaled_text, (SDL_Point){0, 0});
	else if (text->draw_method == CENTERED)
		sdl_merge_surface_alpha_center(dst, scaled_text);
	else if (text->draw_method == REPEAT)
		sdl_merge_surface_alpha_repeat(dst, scaled_text);
}

void				draw_text(SDL_Surface *dst, t_text *text, SDL_Point abs_dim)
{
	TTF_Font	*font;
	SDL_Surface	*rendered_text;
	SDL_Surface	*scaled_text;

	if (text->color.a == 0 || text->text == NULL || ft_strisempty(text->text))
		return ;
	font = text->fonts[text->font_type];
	rendered_text = render_text(text->text, font, &text->color);
	scaled_text = scale_text(rendered_text, text->size, abs_dim);
	SDL_FreeSurface(rendered_text);
	if (text->draw_method != SCALED)
		merge_text(dst, text, scaled_text);
	else
		sdl_merge_surface_alpha_scaled(dst, scaled_text);
	SDL_FreeSurface(scaled_text);
}
