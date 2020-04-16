/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_fc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 15:29:58 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 15:35:45 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "renderer.h"
#include "rinfo.h"

void		render_fc(t_rinfo *rin, t_hinfo *info)
{
	if (!info->sec->has_slope)
		draw_floor(rin, info);
	else
		draw_sfloor(rin, info);
	if (info->sec->has_ceiling)
		draw_ceil(rin, info);
}
