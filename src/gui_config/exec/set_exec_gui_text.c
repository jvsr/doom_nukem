/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_exec_gui_text.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 21:18:58 by pholster       #+#    #+#                */
/*   Updated: 2019/10/02 21:18:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"
#include "exec.h"
#include "parse.h"
#include "color.h"
#include "error.h"

static void	validate(t_parse_info *elem_info,
						t_draw_method draw_method, t_font_type font_type)
{
	char	*msg;

	msg = "";
	if (elem_info->text_draw_method && draw_method == DRAW_METHOD_UNDEFINED)
		msg = ft_strformat("Invalid text draw method in %s", elem_info->name);
	else if (elem_info->text_font && font_type == FONT_UNDEFINED)
		msg = ft_strformat("Invalid text font in %s", elem_info->name);
	if (ft_strequ(msg, "") == FALSE)
		error_msg("Executer validation error", 21, msg);
}

void		set_exec_gui_text(t_transform *elem, t_parse_info *elem_info)
{
	SDL_Color		color;
	t_draw_method	draw_method;
	t_font_type		font_type;

	font_type = get_font_type_value(elem_info->text_font);
	draw_method = get_draw_method_value(elem_info->text_draw_method);
	validate(elem_info, draw_method, font_type);
	hex_to_color(&color, elem_info->text_color);
	set_elem_text_str(elem, elem_info->text);
	set_elem_text_color(elem, color);
	set_elem_text_size(elem, elem_info->text_size);
	if (font_type != FONT_UNDEFINED)
		set_elem_text_font(elem, font_type);
	if (draw_method != DRAW_METHOD_UNDEFINED)
		set_elem_text_draw_method(elem, draw_method);
}
