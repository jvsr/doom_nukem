/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_part.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 14:38:53 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/28 15:00:30 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include "libft/ft_list.h"
#include "campaign.h"
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

static void		draw_coloumn(t_coord *coords, t_campaign_wall *wall,
					t_game *game, int x, t_renderinfo *r_in, t_campaign_sector *sector)
{
	float	dist;
	float	screen;
	int		i;
	int		hb;
	float	tmp;

	(void)wall;
	dist = get_distance(&coords[0], &coords[1]) *
			cosf(game->player->angle * PI_R); 
	tmp = r_in->b_vec.y * r_in->ratio * dist;
	screen = 2 * get_distance(&(t_coord){0, tmp},
			&(t_coord){0, game->player->height});
	i = ((get_distance(&(t_coord){0, sector->height_floor}, &(t_coord){0, tmp})) / screen) *
			r_in->dst->h;
	hb = ((get_distance(&(t_coord){0, sector->height_floor + (sector->height_wall)},
			&(t_coord){0, tmp})) / screen) * r_in->dst->h;
	while (i < hb)
	{
		draw_point(0xFFFFFFFF, r_in->dst, r_in->mask, (t_point){x, i});
		i++;
	}
}

static void		draw_wall(t_coord range,t_game *game, t_campaign_wall *wall,
					t_renderinfo *r_in)
{
	float	ray;
	float	step;
	t_campaign_sector *sector;
	t_coord	pos;
	t_coord origin;
	t_coord hit;

	ray = range.x;
	step = game->setting->fov / r_in->dst->w;
	origin = (t_coord){game->player->forward.x + game->player->pos.x,
		game->player->forward.y + game->player->pos.y};
	pos = (t_coord){game->player->forward.y, -game->player->forward.x};
	origin  = (t_coord){origin.x + (pos.x * (range.x - (game->setting->fov /
		RENDER_THREAD_COUNT))), origin.y + (pos.y * (range.x -
		(game->setting->fov / RENDER_THREAD_COUNT)))};
	sector = get_sector(wall->sector_tag, game->campaign->sector);
	while (ray < range.y)
	{
		if (get_collision(&(t_coord){game->player->pos.x, game->player->pos.y},
		&game->player->forward,
		(t_coord[]){*wall->vertex_begin, *wall->vertex_end}, &hit) != NULL)
			draw_coloumn((t_coord[]){hit, origin}, wall, game, (int)((ray /
				game->setting->fov) * r_in->dst->w), r_in, sector);
		origin = (t_coord){origin.x + (pos.x * step), origin.y +
			(pos.y * step)};
		ray += step;
	}
}



void		   	render_part(t_game *game,
						t_coord range, t_list *walls, t_renderinfo *renderinfo)
{
	t_campaign_wall *wall;

	if (!walls)
		return ;
	wall = get_closest(walls, &(game->player->pos));
	while (wall)
	{
		printf("Hey\n");
		draw_wall(range, game, wall, renderinfo);
		wall = get_closest(walls, &(game->player->pos));
	}
}
