/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroyimage.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:48:27 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 11:44:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_string.h"
#include "libft/ft_list.h"

void		destroyimage(t_gui *ui, t_image **image,
												const t_bool delchildren)
{
	t_image *img;

	img = *image;
	if (img->transform.onclick != NULL)
		destroyclick(ui, img->transform.name);
	if (delchildren == TRUE)
		destroychildren(ui, img->transform.children, TRUE);
	else if (img->transform.parent != NULL)
		ft_lstadd(&img->transform.parent->children,
			img->transform.children);
	SDL_FreeSurface(img->texture);
	ft_strdel(&img->transform.name);
	free(img);
	image = NULL;
}
