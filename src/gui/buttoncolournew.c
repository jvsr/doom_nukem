/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   buttoncolournew.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 16:58:48 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/06 12:20:57 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "init.h"
#include "libft/ft_memory.h"
#include "libft/ft_string.h"
#include "color.h"
#include "sdl_extra.h"

t_button	*buttoncolournew(t_guiinfo *guiinfo, char *text,
			t_font *font, const t_color colour)
{
	t_button *button;

	button = (t_button*)ft_memalloc(sizeof(t_button));
	button->texture = SDL_CreateRGBSurface(0,
		INIT_WIDTH * guiinfo->size.x, INIT_HEIGHT * guiinfo->size.y,
		32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
	button->text = ft_strdup(text);
	sdl_surface_draw_rect(button->texture, colour,
					(SDL_Rect){0, 0, button->texture->w, button->texture->h});
	ft_memcpy(&button->font, font, sizeof(t_font));
	ft_memcpy(&button->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&button->size, &guiinfo->size, sizeof(t_coord));
	button->transform.name = ft_strdup(guiinfo->name);
	button->transform.children = NULL;
	button->transform.guitype = BUTTON;
	button->transform.guielem = (void*)button;
	button->transform.onclick = NULL;
	button->transform.visible = TRUE;
	button->transform.layer = 0;
	return (button);
}
