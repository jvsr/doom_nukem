/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_attr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/11 14:06:35 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/11 14:06:35 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "parse.h"

static t_return_code	get_text_attr(const char *type)
{
	if (ft_strequ(type, "text"))
		return (text);
	else if (ft_strequ(type, "text_color"))
		return (text_color);
	else if (ft_strequ(type, "text_font"))
		return (text_font);
	else if (ft_strequ(type, "text_size"))
		return (text_size);
	else if (ft_strequ(type, "text_draw_method"))
		return (text_draw_method);
	return (fail);
}

t_return_code			get_attr(const char *type)
{
	if (ft_strequ(type, "pos"))
		return (pos);
	else if (ft_strequ(type, "dim"))
		return (dim);
	else if (ft_strequ(type, "layer"))
		return (layer);
	else if (ft_strequ(type, "onclick"))
		return (onclick);
	else if (ft_strequ(type, "clickable"))
		return (clickable);
	else if (ft_strequ(type, "show"))
		return (show);
	else if (ft_strequ(type, "texture"))
		return (texture);
	else if (ft_strequ(type, "color"))
		return (color);
	else if (ft_strequ(type, "draw_method"))
		return (draw_method);
	else
		return (get_text_attr(type));
}
