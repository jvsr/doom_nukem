/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_image.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 17:26:08 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/24 15:20:28 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_mem.h"

#include "gui.h"
#include "error.h"

/*
** * Gui internal function
*/

t_image		*new_image(void)
{
	t_image *image;

	image = (t_image *)ft_memalloc(sizeof(t_image));
	if (image == NULL)
		error_msg_errno("Failed to alloc image");
	image->draw_method = SCALED;
	return (image);
}