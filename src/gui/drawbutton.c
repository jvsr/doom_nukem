/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawbutton.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 10:31:06 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 14:00:39 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "gui.h"
#include "sdl_extra.h"
#include "init.h"
#include "error.h"

void		drawbutton(t_gui *ui, t_button *button)
{
	SDL_Surface *fontsurface;
	SDL_Surface *dst;
	SDL_Point	pixel;

	fontsurface = gettextsurface(ui, button->text, button->font);
	dst = SDL_CreateRGBSurface(0, (int)((float)INIT_WIDTH * button->size.x),
		(int)((float)INIT_HEIGHT * button->size.y), 32,
		0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	if (dst == NULL)
		error_msg(strerror(errno), errno);
	SDL_BlitScaled(button->texture, NULL, dst, NULL);
	pixel = (SDL_Point){(int)((float)INIT_WIDTH * button->transform.position.x),
			(int)((float)INIT_HEIGHT * button->transform.position.y)};
	sdl_merge_surface_alpha(dst, fontsurface, (SDL_Point){0, 0});
	sdl_merge_surface(ui->guisurface, dst, pixel);
	SDL_FreeSurface(fontsurface);
	SDL_FreeSurface(dst);
}
