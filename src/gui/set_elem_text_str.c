/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_text_str.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 17:05:26 by pholster       #+#    #+#                */
/*   Updated: 2019/09/18 17:05:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"

void	set_elem_text_str(t_transform *elem, const char *str)
{
	t_text	*text;

	if (elem->gui_type == TEXT)
		text = elem->gui_elem.text;
	else
		text = elem->gui_elem.button->text;
	text->str = ft_strdup(str);
	set_elem_redraw(elem);
}
