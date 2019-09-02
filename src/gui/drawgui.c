/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawgui.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 16:09:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/02 13:59:35 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"

void			drawgui(t_game *game)
{
	t_list *lst;

	if (game->ui.redraw == TRUE)
	{
		lst = game->ui.transform.children;
		while (lst != NULL)
		{
			drawelem(&game->ui, lst->content);
			lst = lst->next;
		}
	}
	sdl_surface_merge(game->surface, game->ui.guisurface, (t_pixel){0, 0});
	game->ui.redraw = FALSE;
}
