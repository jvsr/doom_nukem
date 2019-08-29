/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   imagedestroy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:48:27 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/29 11:33:06 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"

void		imagedestroy(t_image *image, const t_bool destroychildren)
{
	if (destroychildren == TRUE)
		childrendestroy(&image->transform.children, TRUE);
	else if (&image->transform.parent != NULL)
		ft_lstadd(&image->transform.parent->children,
			image->transform.children);
	SDL_FreeSurface(&image->texture);
	free(image);
	image = NULL;
}
