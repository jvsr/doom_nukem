/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel_from_pos.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/09 18:55:48 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/25 14:16:56 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "error.h"
#include "tga.h"

static int	b32(unsigned char *str, size_t i)
{
	unsigned int	ret;

	ret = 0;
	ret |= str[i + 3] << 24;
	ret |= str[i];
	ret |= str[i + 1] << 8;
	ret |= str[i + 2] << 16;
	return (ret);
}

static int	b24(unsigned char *str, size_t i)
{
	unsigned int	ret;

	ret = 0xFF << 24;
	ret |= str[i];
	ret |= str[i + 1] << 8;
	ret |= str[i + 2] << 16;
	return (ret);
}

int			pixel_from_pos(unsigned char *str, size_t i, t_img *img)
{
	if (img->px_depth == 32)
		return (b32(str, i));
	if (img->px_depth == 24)
		return (b24(str, i));
	if (img->px_depth == 16 || img->px_depth == 15)
		(void)b24;
	if (img->px_depth == 8)
		(void)b24;
	error_msg("Unsupported Format", 19,
		ft_strformat("Format %hhd isn't supported", img->px_depth));
	return (0);
}
