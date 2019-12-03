/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_gview.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:30:24 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/03 17:30:24 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL2/SDL_surface.h>

#include "gui.h"

/*
** * Gui internal function
*/

void		del_gview(t_gview **gview)
{
	if (gview == NULL || *gview == NULL)
		return ;
	free(*gview);
	*gview = NULL;
}
