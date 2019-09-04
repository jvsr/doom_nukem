/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   textsurfaceget.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 10:43:56 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 18:33:28 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "init.h"

SDL_Surface	*textsurfaceget(t_gui *ui, char *text, t_font fonttype)
{
	TTF_Font	*font;
	SDL_Surface	*surface;
	SDL_Surface	*dst;
	SDL_Surface	*fsurface;

	dst = NULL;
	font = fontget(ui, fonttype.font);
	surface = TTF_RenderText_Solid(font, text, fonttype.colour);
	fsurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA4444, 0);
	SDL_FreeSurface(surface);
	dst = SDL_CreateRGBSurface(0, (int)((float)INIT_WIDTH * fonttype.size),
			(int)((float)INIT_HEIGHT * fonttype.size), 32,
			0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_BlitScaled(fsurface, NULL, dst, NULL);
	SDL_FreeSurface(fsurface);
	return (dst);
}
