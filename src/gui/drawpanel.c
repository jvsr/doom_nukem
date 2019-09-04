/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawpanel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 13:48:38 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 13:57:53 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "libft/ft_list.h"

static void	drawchildren(t_gui *gui, t_transform *parent)
{
	t_list *lst;

	lst = parent->children;
	while (lst != NULL)
	{
		drawelem(gui, (t_transform*)lst->content);
		lst = lst->next;
	}
}

void		drawpanel(t_gui *ui, t_panel *panel)
{
	SDL_Surface *dst;
	t_pixel		pixel;
	t_gui		gui;

	dst = SDL_CreateRGBSurface(0, INITWIDTH, INITHEIGHT, 32, 0, 0, 0, 0);
	pixel = (t_pixel){(int)((float)INITWIDTH * panel->transform.position.x),
			(int)((float)INITHEIGHT * panel->transform.position.y)};
	gui.font[0] = ui->font[0];
	gui.font[1] = ui->font[1];
	gui.guisurface = dst;
	drawchildren(&gui, &panel->transform);
	sdl_surface_merge(ui->guisurface, dst, pixel);
	SDL_FreeSurface(dst);
}
