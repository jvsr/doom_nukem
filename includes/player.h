/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 16:16:11 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 17:28:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include <_types/_uint8_t.h>
#include <_types/_uint32_t.h>

#include "coord.h"

typedef struct	s_player
{
	t_vec		pos;
    uint32_t    ang;
	uint8_t		cur_sector;
	uint8_t		hp;
	uint8_t		ammo;
	uint8_t		attk;
}				t_player;

#endif
