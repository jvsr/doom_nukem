/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawbutton.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 10:31:06 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 18:33:55 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "init.h"

void		drawbutton(t_gui *ui, t_button *button)
{
	SDL_Surface *fontsurface;
	SDL_Surface *dst;
	t_pixel		pixel;
	TTF_Font	*font;

	font = fontget(ui, button->font.font);
	fontsurface = textsurfaceget(ui, button->text, button->font);
	dst = SDL_CreateRGBSurface(0, (int)((float)INIT_WIDTH * button->size.x),
		(int)((float)INIT_HEIGHT * button->size.y), 32,
		0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	SDL_BlitScaled(button->texture, NULL, dst, NULL);
	pixel = (t_pixel){(int)((float)INIT_WIDTH * button->transform.position.x),
			(int)((float)INIT_HEIGHT * button->transform.position.y)};
	sdl_surface_merge_alpha(dst, fontsurface, (t_pixel){0, 0});
	sdl_surface_merge(ui->guisurface, dst, pixel);
	SDL_FreeSurface(fontsurface);
	SDL_FreeSurface(dst);
}
