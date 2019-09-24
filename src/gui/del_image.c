/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_image.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:48:27 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 11:44:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL2/SDL_video.h>

#include "gui.h"

/*
** * Gui internal function
*/

void		del_image(t_image **image)
{
	if (image == NULL || *image == NULL)
		return ;
	SDL_FreeSurface((*image)->texture);
	free(*image);
	*image = NULL;
}
