/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawpanel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 13:48:38 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:58:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_list.h"

#include "gui.h"
#include "init.h"
#include "sdl_extra.h"
#include "init.h"
#include "error.h"

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
	SDL_Point	pixel;
	t_gui		gui;

	dst = SDL_CreateRGBSurface(0, INIT_WIDTH, INIT_HEIGHT, 32,
		0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	if (dst == NULL)
		error_msg(strerror(errno), errno);
	pixel = (SDL_Point){(int)((float)INIT_WIDTH * panel->transform.position.x),
			(int)((float)INIT_HEIGHT * panel->transform.position.y)};
	gui.font[0] = ui->font[0];
	gui.font[1] = ui->font[1];
	gui.guisurface = dst;
	drawchildren(&gui, &panel->transform);
	sdl_merge_surface(ui->guisurface, dst, pixel);
	SDL_FreeSurface(dst);
}
