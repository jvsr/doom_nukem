/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_image_texture.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:41:26 by pholster       #+#    #+#                */
/*   Updated: 2019/09/16 16:41:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	set_image_texture(t_image *image, SDL_Surface *texture)
{
	image->texture = texture;
}
