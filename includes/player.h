/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 16:16:11 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/22 15:06:45 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include <_types/_t_uint8.h>
# include <_types/_uint32_t.h>

# include "coord.h"

typedef struct	s_player
{
	t_vec		pos;
	uint32_t	ang;
	t_uint8		cur_sector;
	t_uint8		hp;
	t_uint8		ammo;
	t_uint8		attk;
}				t_player;

#endif
