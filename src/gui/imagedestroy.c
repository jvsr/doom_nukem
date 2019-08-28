/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   imagedestroy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:48:27 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/28 17:49:20 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"

void		imagedestroy(t_image *image)
{
	ft_lstdel(&image->transform.children, NULL);
	SDL_FreeSurface(&image->texture);
	free(image);
	image = NULL;
}
