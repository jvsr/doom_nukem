/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_text_surface.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 10:43:56 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:57:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "gui.h"
#include "game.h"
#include "error.h"

static SDL_Surface	*alloc_surface(char *text, t_font font, TTF_Font *ttf_font)
{
	SDL_Surface	*surface;
	SDL_Surface	*formatted;

	surface = TTF_RenderText_Solid(ttf_font, text, font.color);
	if (surface == NULL)
		error_msg(SDL_GetError(), 1);
	formatted = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA4444, 0);
	if (formatted == NULL)
		error_msg(SDL_GetError(), 1);
	SDL_FreeSurface(surface);
	return (formatted);
}

SDL_Surface			*get_text_surface(t_game *game, char *text, t_font font)
{
	TTF_Font	*ttf_font;
	SDL_Surface	*surface;
	SDL_Surface	*dst;

	dst = NULL;
	ttf_font = getfont(game->ui.fonts, font.type);
	surface = alloc_surface(text, font, ttf_font);
	dst = SDL_CreateRGBSurface(0,
			(int)((float)INIT_WIDTH * font.size),
			(int)((float)INIT_HEIGHT * font.size),
			32,
			0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	if (dst == NULL)
		error_msg(SDL_GetError(), 1);
	SDL_BlitScaled(surface, NULL, dst, NULL);
	SDL_FreeSurface(surface);
	return (dst);
}
