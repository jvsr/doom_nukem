/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_rooms.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 16:07:29 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/28 16:57:33 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include "libft/ft_list.h"
#include "game.h"
#include "map.h"
#include "player.h"
#include "renderer.h"

static void		render_wall(t_wall *wall, t_game *game, int *mask)
{
	
}

void			render_rooms(t_game *game, t_level *level)
{
	t_list	*walls;
	int		mask[game->surface->w * game->surface->h];
	t_wall	*cur_wall;

	walls = get_bunches(game, level);
	while (walls)
	{
		cur_wall = get_closest(walls, &game->player->pos);
	}
}
