/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_panel.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 13:48:38 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:58:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

/*
** * Gui internal function
*/

static void	draw_children(t_transform *child)
{
	while (child != NULL)
	{
		draw_elem(child);
		child = child->next;
	}
}

void		draw_panel(SDL_Surface *dst, t_panel *panel)
{
	draw_children(panel->children);
	(void)dst;
}
