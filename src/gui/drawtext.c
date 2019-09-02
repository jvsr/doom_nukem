/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawtext.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 17:27:05 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/02 15:33:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "init.h"

static SDL_Surface	*GetText(t_gui *ui, char *text, t_font fonttype)
{
	TTF_Font	*font;
	SDL_Surface	*surface;
	SDL_Surface	*dst;

	dst = NULL;
	if (fonttype.font == ROBOTO)
		font = ui->font[0];
	else
		font = ui->font[1];
	surface = TTF_RenderText_Solid(font, text, fonttype.colour);
	dst = SDL_CreateRGBSurface(0, (int)((float)WIDTH * fonttype.size),
			(int)((float)HEIGHT * fonttype.size), 32, 0, 0, 0, 0);
	SDL_BlitScaled(surface, NULL, dst, NULL);
	SDL_FreeSurface(surface);
	return (surface);
}

void				drawtext(t_gui *ui, t_text *text)
{
	SDL_Surface *srf;
	t_pixel		pixel;

	srf = GetText(ui, text->text, text->font);
	pixel = (t_pixel){(float)WIDTH * text->transform.position.x,
			(float)HEIGHT * text->transform.position.y};
	sdl_surface_merge(ui->guisurface, srf, pixel);
	SDL_FreeSurface(srf);
}
