/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_map_editor.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 13:18:27 by pholster      #+#    #+#                 */
/*   Updated: 2020/01/17 13:18:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL2/SDL_surface.h>

#include "libft/ft_list.h"

#include "gui.h"
#include "map_editor.h"

/*
** * Gui internal function
*/

void		del_map_editor(t_map_editor **map_editor)
{
	if (map_editor == NULL || *map_editor == NULL)
		return ;
	free(*map_editor);
	*map_editor = NULL;
}
