/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawgui.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 16:09:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/06 13:36:07 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "color.h"
#include "sdl_extra.h"

void			drawgui(t_game *game)
{
	t_list *lst;

	if (game->ui.redraw == TRUE)
	{
		sdl_surface_draw_rect(game->ui.guisurface, (t_color){0, 0, 0, 0},
			(SDL_Rect){0, 0, game->ui.guisurface->w, game->ui.guisurface->h});
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
