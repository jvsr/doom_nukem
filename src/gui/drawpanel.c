/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawpanel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 13:48:38 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 17:34:54 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "init.h"
#include "sdl_extra.h"
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

	dst = SDL_CreateRGBSurface(0, INIT_WIDTH, INIT_HEIGHT, 32, 0, 0, 0, 0);
	pixel = (t_pixel){(int)((float)INIT_WIDTH * panel->transform.position.x),
			(int)((float)INIT_HEIGHT * panel->transform.position.y)};
	gui.font[0] = ui->font[0];
	gui.font[1] = ui->font[1];
	gui.guisurface = dst;
	drawchildren(&gui, &panel->transform);
	sdl_surface_merge(ui->guisurface, dst, pixel);
	SDL_FreeSurface(dst);
}
