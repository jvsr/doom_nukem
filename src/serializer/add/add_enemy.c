/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_enemy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/29 12:48:03 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:56:25 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "serializer.h"
#include "enemy.h"

void		add_enemy(t_enemy *enemy, t_binary *bin)
{
	add_int(enemy->health, bin);
	add_long(enemy->last_seen, bin);
	add_int(enemy->state, bin);
	add_string((char*)get_on_name(enemy->on_los), bin);
	add_string((char*)get_no_name(enemy->no_los), bin);
}
