/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   imagedestroy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:48:27 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 13:42:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_string.h"
#include "libft/ft_list.h"

void		imagedestroy(t_gui *ui, t_image *image,
												const t_bool destroychildren)
{
	if (image->transform.onclick != NULL)
		clickdestroy(ui, image->transform.name);
	if (destroychildren == TRUE)
		childrendestroy(ui, image->transform.children, TRUE);
	else if (image->transform.parent != NULL)
		ft_lstadd(&image->transform.parent->children,
			image->transform.children);
	SDL_FreeSurface(image->texture);
	ft_strdel(&image->transform.name);
	free(image);
	image = NULL;
}
