/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_r_object_index.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:10:33 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/05 15:10:33 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "player.h"
#include "rinfo.h"
#include "types.h"
#include "cmath.h"

void		get_r_object_index(t_game *game, void *anim)
{
	t_anim	*an;

	(void)game;
	an = (t_anim*)anim;
	if (an->angle >= 45 && an->angle < 135)
		an->index = (t_point){0, 0};
	else if (an->angle >= 135 && an->angle < 225)
		an->index = (t_point){3, 0};
	else if (an->angle >= 225 && an->angle < 315)
		an->index = (t_point){1, 0};
	else
		an->index = (t_point){2, 0};
}
