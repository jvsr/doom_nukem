/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawimage.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 16:23:52 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 17:34:10 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "sdl_extra.h"
#include "init.h"

void		drawimage(t_gui *ui, t_image *image)
{
	SDL_Surface *dst;
	SDL_Point		pixel;

	dst = SDL_CreateRGBSurface(0, (int)((float)INIT_WIDTH * image->size.x),
			(int)((float)INIT_HEIGHT * image->size.y), 32, 0, 0, 0, 0);
	SDL_BlitScaled(image->texture, NULL, dst, NULL);
	pixel = (SDL_Point){(int)((float)INIT_WIDTH * image->transform.position.x),
			(int)((float)INIT_HEIGHT * image->transform.position.y)};
	sdl_merge_surface(ui->guisurface, dst, pixel);
	SDL_FreeSurface(dst);
}
