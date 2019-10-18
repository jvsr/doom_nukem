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

static t_return_code	get_text_attr(const char *attr)
{
	if (ft_strequ(attr, "text"))
		return (text);
	else if (ft_strequ(attr, "text_color") || ft_strequ(attr, "text_colour"))
		return (text_color);
	else if (ft_strequ(attr, "text_font"))
		return (text_font);
	else if (ft_strequ(attr, "text_size"))
		return (text_size);
	else if (ft_strequ(attr, "text_draw_method"))
		return (text_draw_method);
	return (fail);
}

t_return_code			get_attr(const char *attr)
{
	if (ft_strequ(attr, "pos"))
		return (pos);
	else if (ft_strequ(attr, "dim"))
		return (dim);
	else if (ft_strequ(attr, "layer"))
		return (layer);
	else if (ft_strequ(attr, "onclick"))
		return (onclick);
	else if (ft_strequ(attr, "clickable"))
		return (clickable);
	else if (ft_strequ(attr, "show"))
		return (show);
	else if (ft_strequ(attr, "texture"))
		return (texture);
	else if (ft_strequ(attr, "color") || ft_strequ(attr, "colour"))
		return (color);
	else if (ft_strequ(attr, "draw_method"))
		return (draw_method);
	else
		return (get_text_attr(attr));
}
