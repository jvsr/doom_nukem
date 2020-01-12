/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgba_intensity.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 14:01:23 by ehollidg       #+#    #+#                */
/*   Updated: 2020/01/12 14:01:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

t_uint32	rgba_intensity(t_uint32 colour, float offset)
{
	colour = (colour & 0xFF00FFFF) |
		((t_uint8)(((colour & 0x00FF0000) >> 16) * offset) << 16);
	colour = (colour & 0xFFFF00FF) |
		((t_uint8)(((colour & 0x0000FF00) >> 8) * offset) << 8);
	colour = (colour & 0xFFFFFF00) |
		(t_uint8)((colour & 0x000000FF) * offset);
	return (colour);
}
