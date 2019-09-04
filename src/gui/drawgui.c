/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawgui.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 16:09:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 14:39:57 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"

void			drawgui(t_game *game)
{
	t_list *lst;

	if (game->ui.redraw == TRUE)
	{
		SDL_FillRect(game->ui.guisurface, NULL, 0);
		lst = game->ui.transform.children;
		while (lst != NULL)
		{
			if (((t_transform*)lst->content)->visible == TRUE)
				drawelem(&game->ui, lst->content);
			lst = lst->next;
		}
		game->ui.redraw = FALSE;
	}
	sdl_surface_merge(game->surface, game->ui.guisurface, (t_pixel){0, 0});
}
