/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawimage.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 16:23:52 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 17:43:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "init.h"

void		drawimage(t_gui *ui, t_image *image)
{
	SDL_Surface *dst;
	t_pixel		pixel;

	dst = SDL_CreateRGBSurface(0, (int)((float)INIT_WIDTH * image->size.x),
			(int)((float)INIT_HEIGHT * image->size.y), 32, 0, 0, 0, 0);
	SDL_BlitScaled(image->texture, NULL, dst, NULL);
	pixel = (t_pixel){(int)((float)INIT_WIDTH * image->transform.position.x),
			(int)((float)INIT_HEIGHT * image->transform.position.y)};
	sdl_surface_merge(ui->guisurface, dst, pixel);
	SDL_FreeSurface(dst);
}
