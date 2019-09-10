/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gettextsurface.c                                   :+:    :+:            */
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
#include "init.h"
#include "error.h"

SDL_Surface	*gettextsurface(t_gui *ui, char *text, t_font fonttype)
{
	TTF_Font	*font;
	SDL_Surface	*surface;
	SDL_Surface	*dst;
	SDL_Surface	*fsurface;

	dst = NULL;
	font = getfont(ui, fonttype.font);
	surface = TTF_RenderText_Solid(font, text, fonttype.colour);
	fsurface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA4444, 0);
	SDL_FreeSurface(surface);
	dst = SDL_CreateRGBSurface(0, (int)((float)INIT_WIDTH * fonttype.size),
			(int)((float)INIT_HEIGHT * fonttype.size), 32,
			0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	if (dst == NULL)
		error_msg(strerror(errno), errno);
	SDL_BlitScaled(fsurface, NULL, dst, NULL);
	SDL_FreeSurface(fsurface);
	return (dst);
}
