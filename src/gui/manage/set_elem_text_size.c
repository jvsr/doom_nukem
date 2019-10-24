/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_text_size.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 17:05:26 by pholster       #+#    #+#                */
/*   Updated: 2019/09/18 17:05:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	set_elem_text_size(t_transform *elem, float size)
{
	t_text	*text;

	if (elem->gui_type == TEXT)
		text = elem->gui_elem.text;
	else
		text = elem->gui_elem.button->text;
	text->size = size;
	set_elem_redraw(elem);
}
