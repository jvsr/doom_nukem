/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   exec_get_color.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 14:39:36 by pholster       #+#    #+#                */
/*   Updated: 2019/10/04 14:39:36 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_char.h"
#include "libft/ft_str.h"

#include "parse.h"

static t_uint8	convert_2(char *pair)
{
	const char	*base_str = "0123456789ABCDEF";
	t_uint8		result;

	result = ft_chrindex(base_str, pair[0]);
	result = (result * 16) + ft_chrindex(base_str, pair[1]);
	return (result);
}

void			exec_get_color(SDL_Color *color, char *color_string)
{
	const size_t	len = ft_strlen(color_string);

	ft_strtoupper(color_string);
	color->r = convert_2(&color_string[0]);
	color->g = convert_2(&color_string[2]);
	color->b = convert_2(&color_string[4]);
	if (len == 8)
		color->a = convert_2(&color_string[6]);
	else
		color->a = 255;
}
