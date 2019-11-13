/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_rooms.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 16:07:29 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/13 11:18:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <SDL2/SDL_surface.h>
#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "game.h"
#include "map.h"
#include "player.h"
#include "renderer.h"

void			render_rooms(t_game *game, t_level *level)
{
	t_list	*walls;
	int		mask[game->surface->w * game->surface->h];

	ft_bzero(mask, game->surface->w * game->surface->h);
	walls = get_bunches(game, level);
}
