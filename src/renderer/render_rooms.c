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

#include <math.h>
#include <SDL2/SDL_surface.h>
#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "game.h"
#include "map.h"
#include "player.h"
#include "renderer.h"

static void		draw_point(int colour,
							SDL_Surface *surface, int *mask, t_point pos)
{
	int pos_1d;
	int *pixels;

	pos_1d = (pos.y * surface->w) + pos.x;
	if (pos.x >= 0 && pos.y >= 0 && pos.x < surface->w && pos.y < surface->h &&
			!mask[pos_1d])
	{
		mask[pos_1d] = 1;
		pixels = surface->pixels;
		pixels[pos_1d] = colour;
	}
}

void			render_rooms(t_game *game, t_level *level)
{
	t_list	*walls;
	int		mask[game->surface->w * game->surface->h];
	t_wall	*cur_wall;

	ft_bzero(mask, game->surface->w * game->surface->h);
	walls = get_bunches(game, level);
}
