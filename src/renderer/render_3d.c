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

void			draw_vline(SDL_Surface *dst, t_drawinfo draw, t_wall *wall, t_wallbounds bounds)
{
	int	*pixels;
	int *img_pixels;
	int i;

	pixels = (int*)dst->pixels;
	draw.y0 = ft_constrain(draw.y0, 0, dst->h - 1);
	draw.y1 = ft_constrain(draw.y1, 0, dst->h - 1);
	if (draw.y1 > draw.y0)
	{
		if (draw.draw.image == NULL)
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
		else
		{
			float x = (float)(draw.draw.x - draw.draw.beginx) / cosf(bounds.anglea * PI_R);
			float percentage = bounds.dista * wall->xperc;
			if (percentage == 0)
				percentage = 0.00001;
			int prop_x = ((float)((int)x % (int)percentage) / percentage) * draw.draw.image->w;
			img_pixels = (int*)draw.draw.image->pixels;
			i = draw.y0;
			while (i <= draw.y1)
			{
				int rel = draw.draw.endy - draw.draw.beginy;
				if (rel == 0)
					rel = 1;
				int y = ((float)((i - draw.draw.beginy) % rel) / rel) * draw.draw.image->h;
				int img_pos = y * draw.draw.image->w + prop_x;
				pixels[i * dst->w + draw.x] = img_pixels[img_pos];
				i++;
			}
		}
	}
}

t_wallbounds	get_wallbounds(t_point xvalues,
								t_point y[2], t_point ny[2], t_bool is_portal)
{
	t_wallbounds	bounds;
	int				x_diff;

	(void)is_portal;
	(void)ny;
	x_diff = xvalues.y - xvalues.x;
	bounds.x = xvalues;
	bounds.ya = (t_point){y[0].x, x_diff * (y[1].x - y[0].x) / x_diff + y[0].x};
	bounds.yb = (t_point){y[0].y, x_diff * (y[1].y - y[0].y) / x_diff + y[0].y};
	bounds.dista = get_distance(&(t_coord){xvalues.x, bounds.ya.x},
								&(t_coord){xvalues.y, bounds.ya.y});
	bounds.distb = get_distance(&(t_coord){xvalues.x, bounds.yb.x},
								&(t_coord){xvalues.y, bounds.yb.y});
	bounds.anglea = sinf(((float)x_diff / bounds.dista) * PI_R);
	bounds.angleb = sinf(((float)x_diff / bounds.distb) * PI_R);
	return (bounds);
}

void			render_3d(t_game *game, SDL_Surface *dst)
{
	t_ritem renders[MAX_RENDERS];
	int yTop[dst->w];
	int yBottom[dst->w];
	int i, k, count, r_max;
	float hfov, vfov;

	hfov = (MAX_FOV - game->setting->fov) + MIN_FOV;
	vfov = (calc_vfov(hfov, dst->w, dst->h) / VFOV_RANGE) * (float)dst->h;
	hfov = (hfov / HFOV_RANGE) * (float)dst->w;
	ft_bzero(yTop, dst->w * 4);
	ft_memset4(yBottom, dst->h - 1, dst->w);
	count = 0;
	r_max = 1;
	t_sector *sectors = game->map->sectors;
	if (game->player->cur_sector > game->map->sector_count)
		return;
	renders[0] = (t_ritem){&sectors[game->player->cur_sector], 0, dst->w - 1};
	while (count < r_max)
	{
		t_wall *walls = renders[count].sector->walls;
		k = 0;
		while ((t_uint64)k < renders[count].sector->wall_count)
		{
			t_coord v0 = {walls[k].corner_0.x - game->player->pos.x, walls[k].corner_0.y - game->player->pos.y};
			t_coord v1 = {walls[k].corner_1.x - game->player->pos.x, walls[k].corner_1.y - game->player->pos.y};

			t_mag *p = &game->player->mag;
			t_coord t0 = {v0.x * p->sin - v0.y * p->cos, v0.x * p->cos + v0.y * p->sin};
			t_coord t1 = {v1.x * p->sin - v1.y * p->cos, v1.x * p->cos + v1.y * p->sin};
			if (t0.y <= 0 && t1.y <= 0)
			{
				k++;
				continue;
			}
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
			if (x0 >= x1 || x1 < renders[count].beginx || x0 > renders[count].endx)
			{
				k++;
				continue;
			}
			float yceil = renders[count].sector->ceil - game->player->height - game->player->heightoffset;
			float yfloor = renders[count].sector->floor - game->player->height - game->player->heightoffset;

			float nyceil = 0;
			float nyfloor = 0;
			if (walls[k].is_portal)
			{
				nyceil = walls[k].window->ceil - game->player->height - game->player->heightoffset;
				nyfloor = walls[k].window->floor - game->player->height - game->player->heightoffset;
			}

			t_point y1 = {dst->h / 2 - (int)(yceil * scale0.y), dst->h / 2 - (int)(yfloor * scale0.y)};
			t_point y2 = {dst->h / 2 - (int)(yceil * scale1.y), dst->h / 2 - (int)(yfloor * scale1.y)};

			t_point ny1 = {dst->h / 2 - (int)(nyceil * scale0.y), dst->h / 2 - (int)(nyfloor * scale0.y)};
			t_point ny2 = {dst->h / 2 - (int)(nyceil * scale1.y), dst->h / 2 - (int)(nyfloor * scale1.y)};

			t_point xvalues = {(int)fmaxf(x0, renders[count].beginx), (int)fminf(x1, renders[count].endx)};
			t_wallbounds bounds = get_wallbounds((t_point){x0, x1}, (t_point[2]){y1, y2}, (t_point[2]){ny1, ny2}, walls[k].is_portal);
			i = xvalues.x;
			while (i <= xvalues.y)
			{
				float light = (MAX_LIGHT_DIST - clamp_float((float)((i - x0) * (t1.y - t0.y) / (x1 - x0) + t0.y), 0, MAX_LIGHT_DIST)) / MAX_LIGHT_DIST;
				int ya = (i - x0) * (y2.x - y1.x) / (x1 - x0) + y1.x;
				int cya = ft_constrain(ya + (game->player->updown * dst->h), yTop[i], yBottom[i]);
				int yb = (i - x0) * (y2.y - y1.y) / (x1 - x0) + y1.y;
				int cyb = ft_constrain(yb + (game->player->updown * dst->h), yTop[i], yBottom[i]);
				
				/* Draw Ceiling (Colour Green)*/
				draw_vline(dst, (t_drawinfo){i, yTop[i], cya - 1, 0, 0xFF66FF66, 0, (t_iminfo){NULL, i, x0, x1, yTop[i], ya - 1}}, &walls[k], bounds);
				/* Draw Floor (Colour Blue)*/
				draw_vline(dst, (t_drawinfo){i, cyb + 1, yBottom[i], 0, 0xFF0000cc, 0, (t_iminfo){NULL, i, x0, x1, yb + 1, yBottom[i]}}, &walls[k], bounds);
				/* Draw Wall (Colour White) / Portal (Colour Red)*/
				if (walls[k].is_portal)
				{
					int nya = (i - x0) * (ny2.x - ny1.x) / (x1 - x0) + ny1.x;
					int cnya = ft_constrain(nya + (game->player->updown * dst->h), yTop[i], yBottom[i]);
					int nyb = (i - x0) * (ny2.y - ny1.y) / (x1 - x0) + ny1.y;
					int cnyb = ft_constrain(nyb + (game->player->updown * dst->h), yTop[i], yBottom[i]);

					/* Between our ceiling and the new sector ceiling */
					draw_vline(dst, (t_drawinfo){i, cya, cnya - 1, 0, i==x0||i==x1 ? 0 : rgba_intensity(0xFF800080, light), 0, (t_iminfo){get_texture(game, walls[k].texture), i, x0, x1, ya + (game->player->updown * dst->h), nya - 1 + (game->player->updown * dst->h)}}, &walls[k], bounds);
					yTop[i] = ft_constrain(ft_max(cya, cnya), yTop[i], dst->h - 1);

					/* Between our floor and the new sector floor */
					draw_vline(dst, (t_drawinfo){i, cnyb+1, cyb, 0, i==x0||i==x1 ? 0 : rgba_intensity(0xFF800080, light), 0, (t_iminfo){get_texture(game, walls[k].texture), i, x0, x1, nyb+1 + (game->player->updown * dst->h), yb + (game->player->updown * dst->h)}}, &walls[k], bounds);
    	            yBottom[i] = ft_constrain(ft_min(cyb, cnyb), 0, yBottom[i]);
				}
				else
					draw_vline(dst, (t_drawinfo){i, cya, cyb, 0, i==x0||i==x1 ? 0 : rgba_intensity(0xffffffff, light), 0, (t_iminfo){get_texture(game, walls[k].texture), i, x0, x1, ya + (game->player->updown * dst->h), yb + (game->player->updown * dst->h)}}, &walls[k], bounds);
				i++;
			}
			if (walls[k].is_portal && xvalues.y > xvalues.x && r_max + 1 < MAX_RENDERS)
			{
				renders[count + 1] = (t_ritem){walls[k].window, xvalues.x, xvalues.y};
				r_max++;
			}
			k++;
		}
		count++;
	}
}
