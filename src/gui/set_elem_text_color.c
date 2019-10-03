/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_text_color.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 17:05:26 by pholster       #+#    #+#                */
/*   Updated: 2019/09/18 17:05:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

#include "gui.h"

void	set_elem_text_color(t_transform *elem, SDL_Color color)
{
	t_text	*text;

	if (elem->gui_type == TEXT)
		text = elem->gui_elem.text;
	else
		text = elem->gui_elem.button->text;
	text->color = color;
	set_elem_redraw(elem);
}
