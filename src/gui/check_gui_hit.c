/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_gui_hit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 11:39:35 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 16:06:31 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>

#include "gui.h"
#include "game.h"

static t_bool		is_hit(SDL_Point *pos, t_transform *elem)
{
	SDL_Point	bottom_right;

	bottom_right.x = elem->abs_pos.x + elem->abs_dim.x;
	bottom_right.y = elem->abs_pos.y + elem->abs_dim.y;
	if (pos->x >= elem->abs_pos.x && pos->x <= bottom_right.x)
		return (pos->y >= elem->abs_pos.y && pos->y <= bottom_right.y);
	else
		return (FALSE);
}

static t_transform	*check_children(SDL_Point *pos, t_transform *elem)
{
	t_transform	*next_hit;

	if (elem == NULL)
		return (NULL);
	next_hit = check_children(pos, elem->next);
	if (next_hit != NULL)
		return (next_hit);
	if (is_hit(pos, elem))
	{
		if (elem->gui_type == PANEL)
			return (check_children(pos, elem->gui_elem.panel->children));
		else if (elem->clickable)
			return (elem);
	}
	return (NULL);
}

t_transform			*check_gui_hit(t_game *game, SDL_Point pos)
{
	return (check_children(&pos, game->ui->children));
}
