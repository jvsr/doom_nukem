/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_set_gui_image.c                               :+:    :+:            */
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
#include "tga.h"
#include "parse.h"
#include "error.h"

static void	validate(t_parse_info *elem_info)
{
	char	*msg;

	msg = "";
	if (elem_info->draw_method >= DRAW_METHOD_AMOUNT)
		msg = ft_strformat("Invalid text draw method in %s", elem_info->name);
	if (ft_strequ(msg, "") == FALSE)
		error_msg_errno(msg);
}

void		exec_set_gui_image(t_transform *elem, t_parse_info *elem_info)
{
	validate(elem_info);
	set_elem_image_color(elem, elem_info->color);
	if (elem_info->img != NULL)
		set_elem_image_texture(elem, open_tga_sdl(elem_info->img));
	if (elem_info->draw_method != DRAW_METHOD_UNDEFINED)
		set_elem_image_draw_method(elem, elem_info->draw_method);
}
