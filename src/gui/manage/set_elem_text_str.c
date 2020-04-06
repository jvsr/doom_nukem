/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_text_str.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 17:05:26 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:12:22 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"
#include "error.h"

void	set_elem_text_str(t_transform *elem, const char *str)
{
	t_text	*text;

	if (elem->gui_type == TEXT)
		text = elem->gui_elem.text;
	else
		text = elem->gui_elem.button->text;
	if (text->text != NULL)
		free(text->text);
	text->text = ft_strdup(str);
	if (text->text == NULL)
		error_msg_errno("Failed to alloc Text");
	set_elem_redraw(elem);
}
