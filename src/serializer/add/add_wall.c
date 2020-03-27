/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_wall.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 17:20:56 by euan           #+#    #+#                */
/*   Updated: 2020/03/27 21:53:28 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"

void		add_wall(t_wall *wall, t_binary *bin)
{
	add_coord(&wall->corner_0, bin);
	add_coord(&wall->corner_1, bin);
	add_char((char)wall->is_portal, bin);
	add_char((char)wall->is_window, bin);
	add_anim(&wall->texture, bin);
	add_anim(&wall->win_tex, bin);
	add_coord(&wall->perc, bin);
	add_decal_list(wall->decals, bin);
	add_char((char)wall->is_door, bin);
}
