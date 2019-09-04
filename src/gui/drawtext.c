/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawtext.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 17:27:05 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 17:33:43 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "init.h"

void				drawtext(t_gui *ui, t_text *text)
{
	SDL_Surface *srf;
	t_pixel		pixel;

	srf = textsurfaceget(ui, text->text, text->font);
	pixel = (t_pixel){(int)((float)INIT_WIDTH * text->transform.position.x),
			(int)((float)INIT_HEIGHT * text->transform.position.y)};
	sdl_surface_merge(ui->guisurface, srf, pixel);
	SDL_FreeSurface(srf);
}
