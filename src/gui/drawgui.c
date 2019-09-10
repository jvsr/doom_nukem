/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawgui.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 16:09:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 17:33:28 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"

#include "gui.h"
#include "sdl_extra.h"
#include "game.h"

#include "libft/ft_printf.h"

void			drawgui(t_game *game)
{
	t_list *lst;

	if (game->ui.redraw == TRUE)
	{
		sdl_draw_surface_rect(game->ui.guisurface, (SDL_Color){0, 0, 0, 0},
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
	sdl_merge_surface(game->surface, game->ui.guisurface, (SDL_Point){0, 0});
}
