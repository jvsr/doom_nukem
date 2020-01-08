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

void	draw_vline(SDL_Surface *dst, t_drawinfo draw)
{
	int	*pixels;
	int i;

	pixels = (int*)dst->pixels;
	draw.y0 = clamp_float(draw.y0, 0, dst->h - 1);
	draw.y1 = clamp_float(draw.y1, 0, dst->h - 1);
	if (draw.y0 == draw.y1)
		pixels[draw.y0 * dst->w + draw.x] = draw.middle;
	else if (draw.y1 > draw.y0)
	{
		pixels[draw.y0 * dst->w + draw.x] = draw.top;
		i = draw.y0 + 1;
		while (i < draw.y1)
		{
			pixels[i * dst->w + draw.x] = draw.middle;
			i++;
		}
		pixels[draw.y1 * dst->w + draw.x] = draw.bottom;
	}
}



void	render_3d(t_game *game, SDL_Surface *dst)
{
	int ytop[dst->w];
	int yBottom[dst->w];
	int renderedSectors[game->map->sector_count];
	int i, k;
	float hfov, vfov;

	hfov = (float)game->setting->fov / (float)360;
	vfov = (float)game->setting->vfov / (float)180;
	ft_bzero(renderedSectors, game->map->sector_count * 4);
	ft_bzero(ytop, dst->w * 4);
	ft_memset4(yBottom, dst->h  - 1, dst->w);
	k = 0;
	t_sector *sectors = game->map->sectors;
	if (game->player->cur_sector > game->map->sector_count)
		return;
	t_wall *walls = sectors[game->player->cur_sector].walls;
	while (k < sectors[game->player->cur_sector].wall_count)
	{
		t_coord v0 = {walls[k].corner_0.x - game->player->pos.x, walls[k].corner_1.y - game->player->pos.y};
		t_coord v1 = {walls[k].corner_0.x - game->player->pos.x, walls[k].corner_1.y - game->player->pos.y};
		
		t_coord p = {cosf(game->player->angle), sinf(game->player->angle)};
		t_coord t0 = {v0.x * p.y - v0.y * p.x, v0.x * p.x + v0.y * p.y};
		t_coord t1 = {v0.x * p.y - v0.y * p.x, v0.x * p.x + v0.y * p.y};
		if (t0.y <= 0 && t1.y <= 0)
			continue;
		if (t0.y <= 0 || t1.y <= 0)
		{
			float near = 1e-4f;
			float far = 5.0;
			float nearside = 1e-5f;
			float farside = 20.0;
			t_coord insec0 = intersect3(t0, t1, (t_coord){-nearside, near}, (t_coord){-farside, far});
			t_coord insec1 = intersect3(t0, t1, (t_coord){nearside, near}, (t_coord){farside, far});
			if (t0.y < near)
			{
					if (insec0.y > 0)
					{
						t0.x = insec0.x;
						t0.y = insec0.y;
					}
					else
					{
						t0.x = insec1.x;
						t0.y = insec1.y;
					}
			}
			if (t1.y < near)
			{
					if (insec0.y > 0)
					{
						t1.x = insec0.x;
						t1.y = insec0.y;
					}
					else
					{
						t1.x = insec1.x;
						t1.y = insec1.y;
					}
			}
		}
		t_coord scale0 = { hfov / t0.y, vfov / t0.y };
		t_coord scale1 = { hfov / t1.y, vfov / t1.y };
		int x0 = dst->w / 2 - (int)(t0.x * scale0.x);
		int x1 = dst->w / 2 - (int)(t1.x * scale1.x);
		if (x0 >= x1 || x1 < 0 || x0 > dst->w - 1)
			continue;
		float yceil = sectors[i].ceil - game->player->height;
		float yfloor = sectors[i].floor - game->player->height;

		t_point y1 = {dst->h / 2 - (int)(yceil * scale0.y), dst->h / 2 - (int)(yfloor * scale0.y)};
		t_point y2 = {dst->h / 2 - (int)(yceil * scale1.y), dst->h / 2 - (int)(yfloor * scale1.y)};
		t_point xvalues = {(int)fminf(x0, 0), (int)fmaxf(x1, dst->w - 1)};
		i = 0;
		while (i <= xvalues.y)
		{
			int ya = (i - x0) * (y2.x - y1.x) / (x1 - x0);
			int cya = ft_constrain(ya, ytop[i], yBottom[i]);
			int yb = (i - x0) * (y2.y - y1.y) / (x1 - x0);
			int cyb = ft_constrain(yb, ytop[i], yBottom[i]);
			/* Draw Ceiling */
			draw_vline(dst, (t_drawinfo){i, ytop[i], cya - 1, 0x111111, 0x222222, 0x111111});
			/* Draw Floor */
			draw_vline(dst, (t_drawinfo){i, cyb + 1, yBottom[i], 0x0000FF, 0x0000AA, 0x0000FF});
			
		}
		k++;
	}
}
