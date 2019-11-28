/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_3d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 16:58:30 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/28 16:57:27 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "game.h"
#include "map.h"
#include "player.h"
#include "renderer.h"

void	render_3d(t_game *game, t_level *level)
{
	static t_bool first = TRUE;

	if (first == TRUE)
	{
		ft_memcpy(&(game->player->pos),
			&level->player_start_pos, sizeof(t_coord));
		ft_memcpy(&game->player->angle,
			&level->player_start_angle, sizeof(t_uint16));
		first = FALSE;
	}
	render_rooms(game, level);
}
