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

#include "gui_internal.h"

/*
** * Gui internal function
*/

static void	draw_children(t_transform *child, t_gui *ui)
{
	while (child != NULL)
	{
		draw_elem(child, ui);
		child = child->next;
	}
}

void		draw_panel(t_panel *panel, t_gui *ui)
{
	draw_children(panel->children, ui);
}
