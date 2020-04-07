/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_exec_gui_image.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 21:18:58 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:45:03 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"
#include "tga.h"
#include "exec.h"
#include "parse.h"
#include "color.h"
#include "error.h"

static void	validate(t_parse_info *elem_info, t_draw_method draw_method)
{
	char	*msg;

	msg = "";
	if (elem_info->draw_method && draw_method == DRAW_METHOD_UNDEFINED)
		msg = ft_strformat("Invalid image draw method in %s", elem_info->name);
	if (ft_strequ(msg, "") == FALSE)
		error_msg("Executer validation error", 21, msg);
}

void		set_exec_gui_image(t_transform *elem, t_parse_info *elem_info,
								char const *exec_path)
{
	SDL_Color		color;
	t_draw_method	draw_method;
	SDL_Surface		*image;

	draw_method = get_draw_method_value(elem_info->draw_method);
	validate(elem_info, draw_method);
	hex_to_color(&color, elem_info->color);
	set_elem_image_color(elem, color);
	if (elem_info->texture[0] != '\0')
	{
		image = open_tga_sdl(elem_info->texture, exec_path);
		set_elem_image_texture(elem, image);
	}
	if (draw_method != DRAW_METHOD_UNDEFINED)
		set_elem_image_draw_method(elem, draw_method);
}
