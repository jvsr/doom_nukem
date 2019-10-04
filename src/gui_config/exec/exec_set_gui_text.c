/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_set_gui_text.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 21:18:58 by pholster       #+#    #+#                */
/*   Updated: 2019/10/02 21:18:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_printf.h"

#include "gui.h"
#include "exec.h"
#include "parse.h"
#include "error.h"

static void	validate(t_parse_info *elem_info)
{
	char	*msg;

	msg = "";
	if (elem_info->text_font >= FONT_AMOUNT)
		msg = ft_strformat("Invalid text font in %s", elem_info->name);
	else if (elem_info->text_draw_method >= DRAW_METHOD_AMOUNT)
		msg = ft_strformat("Invalid text draw method in %s", elem_info->name);
	if (ft_strequ(msg, "") == FALSE)
		error_msg_errno(msg);
}

void		exec_set_gui_text(t_transform *elem, t_parse_info *elem_info)
{
	SDL_Color	text_color;

	validate(elem_info);
	exec_get_color(&text_color, elem_info->text_color);
	set_elem_text_str(elem, elem_info->text);
	set_elem_text_color(elem, text_color);
	set_elem_text_size(elem, elem_info->text_size);
	if (elem_info->text_font != FONT_UNDEFINED)
		set_elem_text_font(elem, elem_info->text_font);
	if (elem_info->text_draw_method != DRAW_METHOD_UNDEFINED)
		set_elem_text_draw_method(elem, elem_info->text_draw_method);
}
