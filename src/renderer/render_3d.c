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
#include "libft/ft_num.h"
#include "game.h"
#include "campaign.h"
#include "player.h"
#include "renderer.h"
#include "cmath.h"
#include "rinfo.h"
#include "setting.h"
#include <math.h>
#include "color.h"
#include "sdl_thread.h"

static void draw_line(SDL_Surface *dst, t_point *ybounds, int x, int colour, t_point *bounds, t_hit *hit, t_game *game)
{
	int *pixels;
	int i;
	t_point c_ybounds;

	pixels = dst->pixels;
	if (x < 0 || x >= dst->w)
		return;
	*bounds = (t_point){ft_constrain(bounds->x, 0, dst->h), ft_constrain(bounds->y, 0, dst->h)};
	c_ybounds.x = ft_constrain(ybounds->x, bounds->x, bounds->y);
	c_ybounds.y = ft_constrain(ybounds->y, c_ybounds.x, bounds->y);
	i = c_ybounds.x;
	if (colour != -1)
	{
		while (i < c_ybounds.y)
		{
			pixels[x + (dst->w * (dst->h - i - 1))] = colour;
			i++;
		}
	}
	else
	{
		SDL_Surface *tex = get_texture(game, TEXTURE_BRICK_WALL);
		int *t_pixels = tex->pixels;
		float perc = get_distance(&hit->pos, &hit->wall->corner_0) / get_distance(&hit->wall->corner_0, &hit->wall->corner_1);
		perc = wrap_float(perc, 0, hit->wall->xperc) / hit->wall->xperc;
		int tex_x = perc * tex->w;
		float intensity = (MAX_LIGHT_DIST - clamp_float(hit->og_dist, 0, MAX_LIGHT_DIST)) / MAX_LIGHT_DIST;
		while (i < c_ybounds.y)
		{
			int y = (wrap_float((float)(i - ybounds->x) / (ybounds->y - ybounds->x), 0, hit->wall->yperc) / hit->wall->yperc) * tex->h;
			pixels[x + (dst->w * (dst->h - i - 1))] = rgba_intensity(t_pixels[(y * tex->w) + tex_x], intensity);
			
			i++;
		}
	}
}

static void		draw_skybox(int x, SDL_Surface *dst, t_game *game, t_point *bounds)
{
	int			*pixels;
	SDL_Surface	*skybox;
	float		perc;
	int			x_pos;
	int			*skybox_pixels;

	pixels = dst->pixels;
	skybox = get_texture(game, game->map->skybox);
	skybox_pixels = skybox->pixels;
	perc = ((float)game->setting->fov / 360) * skybox->w;
	x_pos = ((perc / dst->w) * x) + (wrap_float((float)game->player->angle - (game->setting->fov / 2), 0, 360) / 360) * skybox->w;
	*bounds = (t_point){ft_constrain(bounds->x, 0, dst->h), ft_constrain(bounds->y, 0, dst->h)};
	while (bounds->x < bounds->y)
	{
		pixels[x + ((dst->h - bounds->x - 1) * dst->w)] = skybox_pixels[x_pos + (skybox->h - 1 - (int)(((float)bounds->x / dst->h) * skybox->h)) * skybox->w];
		bounds->x++;
	}
}

static t_point	draw_vline(t_hit *hit, t_game *game, int x, SDL_Surface *dst, t_point *bounds)
{
	float y1, y0, t0, s;
	t_point ybounds;

	t0 = hit->dist * tanf((game->setting->vfov / 2) * PI_R);
	y0 = game->player->height + game->player->heightoffset;
	y1 = y0 + t0;
	y0 -= t0;
	s = t0 * 2;
	ybounds = (t_point){(((hit->sect->floor - y0) / s) * (dst->h)) - game->player->screen_updown,
						dst->h - (((y1 - hit->sect->ceil) / s) * (dst->h)) - game->player->screen_updown};
	if (ybounds.y < dst->h && hit->sect->has_ceiling)
		draw_line(dst, &(t_point){ybounds.y, dst->h}, x, 0xFF00FF00, bounds, hit, game);
	else
		draw_skybox(x, dst, game, &(t_point){ybounds.y, bounds->y});
	if (ybounds.x > 0)
		draw_line(dst, &(t_point){0, ybounds.x}, x, 0xFF0000FF, bounds, hit, game);
	if (!hit->wall->is_portal && hit->sect->ceil > y0 && hit->sect->floor < y1)
		draw_line(dst, &ybounds, x,  -1, bounds, hit, game);
	else if (hit->sect->ceil > y0 && hit->sect->floor < y1)
	{
		t_point nybounds = {(((hit->wall->window->floor - y0) / s) * dst->h) - game->player->screen_updown,
							dst->h - (((y1 - hit->wall->window->ceil) / s) * dst->h) - game->player->screen_updown};
		if (nybounds.x < ybounds.x)
			nybounds.x = ybounds.x;
		if (nybounds.y > ybounds.y)
			nybounds.y = ybounds.y;
		if (nybounds.y > bounds->y)
			nybounds.y = bounds->y;
		if (nybounds.x < bounds->x)
			nybounds.x = bounds->x;
		draw_line(dst, &(t_point){ybounds.x, nybounds.x}, x, -1, bounds, hit, game);
		draw_line(dst, &(t_point){nybounds.y, ybounds.y}, x, -1, bounds, hit, game);
		return (nybounds);
	}
	return ((t_point){0, 0});
}

static t_hit get_hit(t_coord *cosin,
						t_player *player, t_sector *sector, t_sector *prev)
{
	t_uint64 i;
	t_wall *walls;
	t_hit hit;
	t_coord val;
	float dist;

	i = 0;
	walls = sector->walls;
	hit.dist = 2147483646;
	while (i < sector->wall_count)
	{
		if (!(prev != NULL && walls[i].is_portal && walls[i].window == prev) &&
			get_collision(&player->pos, cosin,
							(t_coord[2]){walls[i].corner_0, walls[i].corner_1},
							&val))
		{
			dist = get_distance(&player->pos, &val);
			if (dist < hit.dist)
				hit = (t_hit){dist, dist, val, &walls[i], sector};
		}
		i++;
	}
	return (hit);
}

static void render_chunk(t_game *game, SDL_Surface *dst, int start, int max)
{
	float	angle;
	float	step;
	float	hfov2;
	t_coord	cosin;
	float	r_angle;
	t_hit	hit;
	t_sector *prev;
	t_sector *sec;

	hfov2 = (float)game->setting->fov / 2;
	step = (float)game->setting->fov / dst->w;
	while (start <= max)
	{
		angle = (float)start * step;
		r_angle = wrap_float(angle + (game->player->angle - hfov2), 0, 360) * PI_R;
		cosin = (t_coord){cosf(r_angle), sinf(r_angle)};
		t_point out = {0, dst->h};
		prev = NULL;
		sec = &game->map->sectors[game->player->cur_sector];
		while (out.x != out.y)
		{
			hit = get_hit(&cosin, game->player, sec, prev);
			if (angle > hfov2)
				hit.dist *= cosf((angle - hfov2) * PI_R);
			else if (angle < hfov2)
				hit.dist *= cosf((hfov2 - angle) * PI_R);
			hit.og_dist = hit.dist;
			hit.dist *= LEVEL_MULTIPLIER;
			out = draw_vline(&hit, game, start, dst, &out);
			if (out.x != out.y)
			{
				prev = hit.sect;
				sec = hit.wall->window;
			}
		}
		start++;
	}
}

void render_3d(t_game *game, SDL_Surface *dst)
{
	game->player->screen_updown = game->player->updown * dst->h;
	render_chunk(game, dst, 0, dst->w - 1);
}
