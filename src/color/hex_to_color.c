/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hex_to_color.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 15:14:59 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 11:36:36 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

#include "libft/ft_char.h"
#include "libft/ft_str.h"

static t_uint8	convert_channel(char *channel)
{
	const char	*base_str = "0123456789ABCDEF";
	t_uint8		result;

	result = ft_chrindex(base_str, channel[0]);
	result = (result * 16) + ft_chrindex(base_str, channel[1]);
	return (result);
}

void			hex_to_color(SDL_Color *c, char *hex)
{
	const size_t	len = ft_strlen(hex);

	ft_strtoupper(hex);
	c->r = convert_channel(&hex[0]);
	c->g = convert_channel(&hex[2]);
	c->b = convert_channel(&hex[4]);
	if (len == 8)
		c->a = convert_channel(&hex[6]);
	else
		c->a = 255;
}
