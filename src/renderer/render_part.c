/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_part.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 14:38:53 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/12 14:38:53 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include "libft/ft_list.h"
#include "map.h"
#include "game.h"
#include "player.h"
#include "renderer.h"
#include "setting.h"
#include "cmath.h"

/*
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
*/

static void		draw_wall(t_coord range, t_game *game, t_wall *wall, int *mask)
{
	float	ray;
	float	step;
	int		i;
	t_coord	pos;

	ray = range.x;
	step = game->setting->fov / game->surface->w;
	i = (float)game->surface->w * (range.x / (float)game->setting->fov);
	while (ray < range.y)
	{
		get_collision(game, &game->player->angles[i],
			(t_coord*){&wall->start, &wall->end}, &pos);
		i++;
		ray += step;
	}
}

void		   	render_part(t_game *game,
										t_coord range, t_list *walls, int *mask)
{
	t_wall *wall;

	wall = get_closest(walls, &(game->player->pos));
	while (walls)
	{
		draw_wall(range, game, wall, mask);
		wall = get_closest(walls, &(game->player->pos));
	}
}
