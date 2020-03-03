/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_ftable.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 09:45:51 by euan           #+#    #+#                */
/*   Updated: 2020/03/02 18:49:29 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft/ft_mem.h"
#include "setting.h"
#include "error.h"
#include "cmath.h"
#include "game.h"
#include "player.h"


void		init_ftable(t_game *game)
{
	const size_t	max = game->surface->h + (size_t)ceil(game->surface->h * (fabs(PLAYER_UPDOWN_MIN) + fabs(PLAYER_UPDOWN_MAX)));
	size_t			i;
	float			step;
	float			start;

	game->ftable.table = ft_memalloc(sizeof(float) * max);
	if (game->ftable.table == NULL)
		error_msg_errno("Unable to allocate lookup table");
	game->ftable.size = max;
	i = 0;
	step = 45.0 / (float)max;
	start = 45;
	while (i < max)
	{
		game->ftable.table[i] = tan(start * PI_R);
		start += step;
		i++;
	}
}

void		reinit_ftable(t_game *game)
{
	ft_memdel((void**)&game->ftable.table);
	init_ftable(game);
}
