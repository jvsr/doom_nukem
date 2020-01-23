/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_map_editor.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 13:18:27 by pholster       #+#    #+#                */
/*   Updated: 2020/01/17 13:18:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL2/SDL_surface.h>

#include "gui.h"
#include "map_editor.h"

/*
** * Gui internal function
*/

static void	del_wall_lines(t_wall_line *line)
{
	t_wall_line	*next;

	while (line != NULL)
	{
		next = line->next;
		free(line);
		line = next;
	}
}

void		del_map_editor(t_map_editor **map_editor)
{
	if (map_editor == NULL || *map_editor == NULL)
		return ;
	del_wall_lines((*map_editor)->line);
	free(*map_editor);
	*map_editor = NULL;
}
