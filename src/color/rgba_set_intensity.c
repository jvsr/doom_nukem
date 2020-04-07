/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rgba_set_intensity.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 14:01:23 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:36:19 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

static void	set_channel(t_uint32 *colour, float const offset,
				t_uint32 const mask, t_uint8 const shift)
{
	t_uint32 const	invert_mask = ~mask;

	*colour = (*colour & invert_mask) |
		((t_uint8)(((*colour & mask) >> shift) * offset) << shift);
}

t_uint32	rgba_set_intensity(t_uint32 colour, float offset)
{
	set_channel(&colour, offset, 0x00FF0000, 16);
	set_channel(&colour, offset, 0x0000FF00, 8);
	set_channel(&colour, offset, 0x000000FF, 0);
	return (colour);
}
