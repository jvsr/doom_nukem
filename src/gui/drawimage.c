/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawimage.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 16:23:52 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 11:51:28 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "init.h"

void		drawimage(t_gui *ui, t_image *image)
{
	SDL_Surface *dst;
	t_pixel		pixel;

	dst = SDL_CreateRGBSurface(0, (int)((float)INITWIDTH * image->size.x),
			(int)((float)INITHEIGHT * image->size.y), 32, 0, 0, 0, 0);
	SDL_BlitScaled(image->texture, NULL, dst, NULL);
	pixel = (t_pixel){(int)((float)INITWIDTH * image->transform.position.x),
			(int)((float)INITHEIGHT * image->transform.position.y)};
	sdl_surface_merge(ui->guisurface, dst, pixel);
	SDL_FreeSurface(dst);
}
