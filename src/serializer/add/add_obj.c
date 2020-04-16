/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_obj.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 12:38:40 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:55:27 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"
#include "player.h"

void		add_obj(t_object *obj, t_binary *bin)
{
	add_coord(&obj->pos, bin);
	add_coord(&obj->size, bin);
	add_anim(&obj->img, bin);
	add_char((char)obj->is_enemy, bin);
	add_float(obj->col_radius, bin);
	add_char((char)obj->can_col, bin);
	add_string((char*)get_col_name(obj->on_collide), bin);
	if (obj->is_enemy)
		add_enemy(obj->data, bin);
}
