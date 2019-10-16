/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_text.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:06:16 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/25 12:34:22 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <SDL2/SDL_pixels.h>

#include "libft/ft_mem.h"

#include "gui.h"
#include "error.h"

/*
** * Gui internal function
*/

t_text			*new_text(t_gui *ui)
{
	t_text		*text;
	SDL_Color	color;

	text = (t_text *)ft_memalloc(sizeof(t_text));
	if (text == NULL)
		error_msg_errno("Failed to alloc text");
	text->draw_method = CENTERED;
	text->fonts = ui->fonts;
	text->font_type = ROBOTO;
	text->size = 1;
	color = (SDL_Color){255, 255, 255, 0};
	ft_memcpy(&text->color, &color, sizeof(SDL_Color));
	return (text);
}
