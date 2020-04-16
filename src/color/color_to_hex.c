/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color_to_hex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 15:14:59 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 11:36:11 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>

#include "libft/ft_char.h"
#include "libft/ft_str.h"

#include "error.h"

static void	convert_channel(char *dst, t_uint8 channel)
{
	const char	*base_str = "0123456789ABCDEF";

	dst[0] = base_str[(channel / 16)];
	dst[1] = base_str[(channel % 16)];
}

char		*color_to_hex(SDL_Color c, t_bool include_alpha)
{
	char	*hex;

	if (include_alpha == FALSE)
		hex = ft_strnew(6);
	else
		hex = ft_strnew(8);
	if (hex == NULL)
		error_msg_errno("Failed to alloc hex");
	convert_channel(&hex[0], c.r);
	convert_channel(&hex[2], c.g);
	convert_channel(&hex[4], c.b);
	if (include_alpha == TRUE)
		convert_channel(&hex[6], c.a);
	return (hex);
}
