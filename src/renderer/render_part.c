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

static void		draw_coloumn(t_coord *coords,
									t_wall *wall, int *mask, t_game *game, int x)
{
	float	dist;
	float	hb;
	int		i;

	dist = get_distance(&coords[0], &coords[1]) * cosf(game->player->angle * PI_R);
	hb = 1 - (wall->length / dist);
	if (hb > 1)
		hb = 0;
	hb *= wall->height;
	i = 0;
	while (i < (int)hb)
	{
		draw_point(0xFFFFFFFF, game->surface, mask, (t_point){x, i});
		i++;
	}
}

static void		draw_wall(t_coord range, t_game *game, t_wall *wall, int *mask)
{
	float	ray;
	float	step;
	t_coord	pos;
	t_coord origin;
	t_coord hit;

	ray = range.x;
	step = game->setting->fov / game->surface->w;
	origin = (t_coord){game->player->forward.x + game->player->pos.x, game->player->forward.y + game->player->pos.y};
	pos = (t_coord){game->player->forward.y, -game->player->forward.x};
	origin  = (t_coord){origin.x + (pos.x * (range.x - (game->setting->fov / RENDER_THREAD_COUNT))), origin.y + (pos.y * (range.x - (game->setting->fov / RENDER_THREAD_COUNT)))};
	while (ray < range.y)
	{
		if (get_collision(&(t_coord){game->player->pos.x, game->player->pos.y},
			&game->player->forward,
			(t_coord[]){wall->start, wall->end}, &hit) != NULL)
			draw_coloumn((t_coord[]){hit, origin}, wall, mask, game, 0);
		origin = (t_coord){origin.x + (pos.x * step), origin.y + (pos.y * step)};
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
