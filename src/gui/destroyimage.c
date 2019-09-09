/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroyimage.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:48:27 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 14:21:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_string.h"
#include "libft/ft_list.h"

void		destroyimage(t_gui *ui, t_image *image,
												const t_bool delchildren)
{
	if (image->transform.onclick != NULL)
		destroyclick(ui, image->transform.name);
	if (delchildren == TRUE)
		destroychildren(ui, image->transform.children, TRUE);
	else if (image->transform.parent != NULL)
		ft_lstadd(&image->transform.parent->children,
			image->transform.children);
	SDL_FreeSurface(image->texture);
	ft_strdel(&image->transform.name);
	free(image);
	image = NULL;
}
