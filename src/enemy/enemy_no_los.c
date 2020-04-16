/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enemy_no_los.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 13:51:22 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 11:37:31 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "rinfo.h"

void	reset_func(t_game *game, t_object *obj)
{
	t_enemy	*enemy;

	enemy = obj->data;
	enemy->last_seen = 0;
	(void)game;
}
