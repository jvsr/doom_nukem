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

static t_bool	is_hit(SDL_Point *pos, t_transform *elem)
{
	SDL_Point	bottom_right;

	bottom_right.x = elem->abs_pos.x + elem->abs_dim.x;
	bottom_right.y = elem->abs_pos.y + elem->abs_dim.y;
	if (pos->x >= elem->abs_pos.x && pos->x <= bottom_right.x)
		return (pos->y >= elem->abs_pos.y && pos->y <= bottom_right.y);
	return (FALSE);
}

static t_bool	is_above(const t_transform *elem, const t_transform *hit)
{
	const t_transform	*hit_p = hit->parent.elem;
	const t_transform	*elem_p = elem->parent.elem;

	if (elem_p == hit_p)
		return (elem->layer > hit->layer);
	else if (elem_p != NULL && elem_p->parent.elem == hit_p)
		return (elem_p->layer > hit->layer);
	else if (hit_p != NULL && elem_p == hit_p->parent.elem)
		return (elem->layer > hit_p->layer);
	else
		return (is_above(elem_p, hit_p));
}

static t_bool	check_children(SDL_Point *pos, t_transform *elem,
								t_transform **hit)
{
	if (elem == NULL)
		return (FALSE);
	if (check_children(pos, elem->next, hit))
		return (TRUE);
	if (is_hit(pos, elem) && (*hit == NULL || is_above(elem, *hit)))
	{
		if (elem->gui_type == PANEL)
			return (check_children(pos, elem->gui_elem.panel->children, hit));
		else if (elem->clickable)
		{
			*hit = elem;
			return (TRUE);
		}
	}
	return (FALSE);
}

void			check_gui_hit(t_game *game, SDL_Point pos)
{
	t_transform *hit;

	hit = NULL;
	check_children(&pos, game->ui->children, &hit);
	if (hit != NULL && hit->onclick != NULL)
		hit->onclick(game, hit);
}
