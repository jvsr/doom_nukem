/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_panel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:40:59 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:09:12 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "gui.h"

/*
** * Gui internal function
*/

static void	remove_children(t_panel *panel)
{
	t_transform	*cur;

	cur = panel->children;
	while (cur != NULL)
	{
		del_elem(&cur);
		cur = panel->children;
	}
}

void		del_panel(t_panel **panel)
{
	if (panel == NULL || *panel == NULL)
		return ;
	remove_children(*panel);
	free(*panel);
	*panel = NULL;
}
