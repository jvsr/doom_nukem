/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_tex_for_obj.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 16:44:32 by euan           #+#    #+#                */
/*   Updated: 2020/03/27 17:01:29 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "rinfo.h"
#include "types.h"

static int const	g_texobjs[] = {
	[O_CHAIR] = TEXTURE_CHAIR_FRONT,
	[O_ENEMY] = TEXTURE_ENEMY0_F0,
	[O_HEALTH_PICKUP] = TEXTURE_HEALTH_PICKUP,
	[O_KEY] = TEXTURE_KEYS,
	[O_SPIKE] = TEXTURE_SPIKES,
	[O_START] = TEXTURE_START,
	[O_END] = TEXTURE_END
};

t_texture	get_tex_for_obj(t_obj obj)
{
	return (g_texobjs[obj]);	
}
