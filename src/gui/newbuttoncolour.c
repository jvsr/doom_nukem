/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newbuttoncolour.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 16:58:48 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:56:35 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_memory.h"
#include "libft/ft_string.h"

#include "gui.h"
#include "init.h"
#include "sdl_extra.h"
#include "error.h"

t_button	*newbuttoncolour(t_guiinfo *guiinfo, char *text, t_font *font,
	const SDL_Color colour)
{
	t_button *btn;

	btn = (t_button*)ft_memalloc(sizeof(t_button));
	if (btn == NULL)
		error_msg(strerror(errno), errno);
	btn->texture = SDL_CreateRGBSurface(0, INIT_WIDTH * guiinfo->size.x,
		INIT_HEIGHT * guiinfo->size.y, 32, 0x00ff0000, 0x0000ff00, 0x000000ff,
		0xff000000);
	btn->text = ft_strdup(text);
	btn->transform.name = ft_strdup(guiinfo->name);
	if (btn->text == NULL || btn->transform.name == NULL ||
		btn->texture == NULL)
		error_msg(strerror(errno), errno);
	sdl_draw_surface_rect(btn->texture, colour, (SDL_Rect){0, 0,
		btn->texture->w, btn->texture->h});
	ft_memcpy(&btn->font, font, sizeof(t_font));
	ft_memcpy(&btn->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&btn->size, &guiinfo->size, sizeof(t_coord));
	btn->transform.children = NULL;
	btn->transform.guitype = BUTTON;
	btn->transform.guielem = (void*)btn;
	btn->transform.onclick = NULL;
	btn->transform.visible = TRUE;
	btn->transform.layer = 0;
	return (btn);
}
