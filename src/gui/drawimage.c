/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawimage.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 16:23:52 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:59:38 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "gui.h"
#include "sdl_extra.h"
#include "init.h"
#include "error.h"

void		drawimage(t_gui *ui, t_image *image)
{
	SDL_Surface *dst;
	SDL_Point	pixel;

	dst = SDL_CreateRGBSurface(0, (int)((float)INIT_WIDTH * image->size.x),
			(int)((float)INIT_HEIGHT * image->size.y), 32,
			0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	if (dst == NULL)
		error_msg(strerror(errno), errno);
	SDL_BlitScaled(image->texture, NULL, dst, NULL);
	pixel = (SDL_Point){(int)((float)INIT_WIDTH * image->transform.position.x),
			(int)((float)INIT_HEIGHT * image->transform.position.y)};
	sdl_merge_surface(ui->guisurface, dst, pixel);
	SDL_FreeSurface(dst);
}
