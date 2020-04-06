/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_r_object_index.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/05 15:10:33 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:49:32 by euan          ########   odam.nl         */
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
	float	angle;

	(void)game;
	an = (t_anim*)anim;
	angle = wrap_float(an->angle + an->offset, 0, 360);
	if (angle >= 45 && angle < 135)
		an->index = (SDL_Point){0, 0};
	else if (angle >= 135 && angle < 225)
		an->index = (SDL_Point){3, 0};
	else if (angle >= 225 && angle < 315)
		an->index = (SDL_Point){1, 0};
	else
		an->index = (SDL_Point){2, 0};
}
