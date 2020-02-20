/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_3d.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 16:58:30 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/10 16:47:09 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/ft_mem.h"
#include "libft/ft_num.h"
#include "libft/ft_list.h"
#include "game.h"
#include "color.h"
#include "campaign.h"
#include "player.h"
#include "renderer.h"
#include "cmath.h"
#include "rinfo.h"
#include "setting.h"
#include <math.h>
#include "color.h"

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
		SDL_Surface *tex = tex_from_anim(game, &hit->wall->texture);
		int *t_pixels = tex->pixels;
		float perc = get_distance(&hit->pos, &hit->wall->corner_0) / get_distance(&hit->wall->corner_0, &hit->wall->corner_1);
		perc = wrap_float(perc, 0, hit->wall->perc.x) / hit->wall->perc.x;
		int tex_x = perc * tex->w;
		float intensity = (MAX_LIGHT_DIST - clamp_float(hit->og_dist, 0, MAX_LIGHT_DIST)) / MAX_LIGHT_DIST;
		while (i < c_ybounds.y)
		{
			int y = (wrap_float((float)(i - ybounds->x) / (ybounds->y - ybounds->x), 0, hit->wall->perc.y) / hit->wall->perc.y) * tex->h;
			pixels[x + (dst->w * (dst->h - i - 1))] = rgba_intensity(t_pixels[(y * tex->w) + tex_x], intensity);
			i++;
		}
	}
}

static void draw_wall(SDL_Surface *dst, t_point *ybounds, int x, t_point *bounds, t_hit *hit, t_game *game)
{
	int *pixels;
	int i;
	t_point c_ybounds;
	t_bool check;
	t_list *decals;

	pixels = dst->pixels;
	decals = NULL;
	if (x < 0 || x >= dst->w)
		return;
	*bounds = (t_point){ft_constrain(bounds->x, 0, dst->h), ft_constrain(bounds->y, 0, dst->h)};
	c_ybounds.x = ft_constrain(ybounds->x, bounds->x, bounds->y);
	c_ybounds.y = ft_constrain(ybounds->y, c_ybounds.x, bounds->y);
	i = c_ybounds.x;
	SDL_Surface *tex = tex_from_anim(game, &hit->wall->texture);
	int *t_pixels = tex->pixels;
	float len = get_distance(&hit->wall->corner_0, &hit->wall->corner_1);
	float perc = get_distance(&hit->pos, &hit->wall->corner_0) / len;
	float xperc = wrap_float(perc, 0, hit->wall->perc.x) / hit->wall->perc.x;
	int tex_x = xperc * tex->w;
	float intensity = ((MAX_LIGHT_DIST - clamp_float(hit->og_dist, 0, MAX_LIGHT_DIST)) / MAX_LIGHT_DIST) * hit->sect->light_value;
	check = TRUE;
	if (hit->wall->decals == NULL)
		check = FALSE;
	else if (*decals_on_vline(hit->wall, perc, len, &decals) == NULL)
		check = FALSE;
	if (!check)
		while (i < c_ybounds.y)
		{
			int y = (wrap_float((float)(i - ybounds->x) / (ybounds->y - ybounds->x), 0, hit->wall->perc.y) / hit->wall->perc.y) * tex->h;
			pixels[x + (dst->w * (dst->h - i - 1))] = rgba_intensity(t_pixels[(y * tex->w) + tex_x], intensity);
			i++;
		}
	else
	{
		float height = hit->sect->ceil - hit->sect->floor;
		while (i < c_ybounds.y)
		{
			float yperc = (float)(i - ybounds->x) / (ybounds->y - ybounds->x);
			int y = (wrap_float(yperc, 0, hit->wall->perc.y) / hit->wall->perc.y) * tex->h;
			int colour = t_pixels[(y * tex->w) + tex_x];
			t_list *tmp = decals;
			while (tmp)
			{
				t_decal *d_tmp = tmp->content;
				SDL_Surface *srf = tex_from_anim(game, &d_tmp->texture);
				float size = d_tmp->size.x / len;
				int x_tmp = (wrap_float(perc - d_tmp->pos.x, 0, size) / size) * srf->w;
				size = d_tmp->size.y / height;
				if (yperc >= d_tmp->pos.y && yperc <= d_tmp->pos.y + size)
				{
					y = (wrap_float(yperc - d_tmp->pos.y, 0, size) / size) * srf->h;
					colour = mix_color(colour, ((int*)srf->pixels)[x_tmp + (y * srf->w)]);
				}
				tmp = tmp->next;
			}
			pixels[x + (dst->w * (dst->h - i - 1))] = rgba_intensity(colour, intensity);
			i++;
		}
		ft_lstdel(&decals, NULL);
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
	ybounds = (t_point){(((hit->sect->floor - y0) / s)* (dst->h)) - game->player->screen_updown,
						dst->h - (((y1 - hit->sect->ceil) / s) * (dst->h)) - game->player->screen_updown};
	if (ybounds.y < dst->h && hit->sect->has_ceiling)
		draw_line(dst, &(t_point){ybounds.y, dst->h}, x, CEILING_COLOR, bounds, hit, game);
	else
		draw_skybox(x, dst, game, (t_point[2]){(t_point){ybounds.y, dst->h}, *bounds});
	if (ybounds.x > 0)
		draw_line(dst, &(t_point){0, ybounds.x}, x, FLOOR_COLOR, bounds, hit, game);
	if (!hit->wall->is_portal && hit->sect->ceil > y0 && hit->sect->floor < y1)
		draw_wall(dst, &ybounds, x, bounds, hit, game);
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
		draw_wall(dst, &(t_point){ybounds.x, nybounds.x}, x, bounds, hit, game);
		draw_wall(dst, &(t_point){nybounds.y, ybounds.y}, x, bounds, hit, game);
		return (nybounds);
	}
	return ((t_point){0, 0});
}

static void draw_object(t_list *objs, SDL_Surface *dst, t_game *game, t_zbuf *zbuf)
{
	int *pixels;
	int count;

	pixels = dst->pixels;
	count = 0;
	while (objs)
	{
		float y1, y0, t0, s;
		t_point ybounds;
		t_point c_ybounds;
		t_point xbounds;
		t_point c_xbounds;
		t_objrend *obj = objs->content;
		int x;

		t0 = obj->dist;
		y0 = game->player->height + game->player->heightoffset;
		y1 = y0 + t0;
		y0 -= t0;
		s = t0 * 2;
		ybounds = (t_point){(((obj->sec->floor - y0) / s)* (dst->h)) - game->player->screen_updown,
			dst->h - (((y1 - (obj->obj->size.y + obj->sec->floor)) / s) * (dst->h)) - game->player->screen_updown};
		int diff = (abs(ybounds.y - ybounds.x) * (obj->obj->size.x / obj->obj->size.y)) / 2;
		xbounds = (t_point){obj->x - diff, obj->x + diff};
		c_xbounds.x = ft_constrain(xbounds.x, 0, dst->w - 1);
		c_xbounds.y = ft_constrain(xbounds.y, c_xbounds.x, dst->w - 1);
		x = c_xbounds.x;
		SDL_Surface *tex = tex_from_anim(game, &obj->obj->img);
		while (x < c_xbounds.y)
		{
			if (x >= 0 && x < dst->w && obj->dist < zbuf[x].dist)
			{
				c_ybounds = set_ybounds(obj, game, (t_ybinfo){dst->h, &ybounds}, &zbuf[x]);
				int *t_pixels = tex->pixels;
				float perc = (float)(x - xbounds.x) / (xbounds.y - xbounds.x);
				int tex_x = perc * (tex->w - 1);
				float intensity = ((MAX_LIGHT_DIST - clamp_float(obj->dist, 0, MAX_LIGHT_DIST)) / MAX_LIGHT_DIST) * obj->sec->light_value;
				int i = c_ybounds.x;
				while (i < c_ybounds.y)
				{
					int y = (float)(i - ybounds.x) / (ybounds.y - ybounds.x) * tex->h;
					int im_pixel = t_pixels[((tex->h - y - 1) * tex->w) + tex_x];
					int in_pix = x + (dst->w * (dst->h - i - 1));
					if (im_pixel != 0)
						pixels[in_pix] = mix_color(pixels[in_pix], rgba_intensity(im_pixel , intensity));
					i++;
				}
			}
			x++;
		}
		objs = objs->next;
		count++;
	}
}

static void render_objects(t_list *secs, t_zbuf *zbuf, SDL_Surface *dst, t_game *game, t_coord *range)
{
	t_list		*n_secs;
	t_list		*objects;
	t_sector	*sec;
	t_list		*objs;
	t_object	*obj;

	n_secs = secs;
	objs = NULL;
	float hfov2 = (float)*game->player->fov / 2;
	while (n_secs)
	{
		sec = n_secs->content;
		objects = sec->objects;
		while (objects != NULL)
		{
			obj = objects->content;
			float object_angle = get_object_angle_on_screen(obj, game->player, range);
			if (object_angle >= 0)
			{
				obj->img.angle = object_angle;
				float tmp_angle = calc_fov(range->x, object_angle);
				int screen_space = (int)((tmp_angle / calc_fov(range->x, range->y)) * dst->w);
				float dist = get_distance(&game->player->pos, &obj->pos);
				if (tmp_angle > hfov2)
					dist *= cosf((tmp_angle - hfov2) * PI_R);
				else if (tmp_angle < hfov2)
					dist *= cosf((hfov2 - tmp_angle) * PI_R);
				if (zbuf[screen_space].dist > dist)
					ft_lstaddbck(&objs, ft_lstnew(new_rendobj(obj, sec, (float[2]){dist, object_angle}, screen_space), sizeof(t_objrend)));
			}
			objects = objects->next;
		}
		n_secs = n_secs->next;
	}
	if (objs != NULL)
	{
		ft_lstsort(&objs, sort_objs);
		draw_object(objs, dst, game, zbuf);
		ft_lstdel(&objs, ft_lstdelmem);
	}
}

static void render_chunk(t_game *game, SDL_Surface *dst, int start, int max)
{
	float		angle;
	float		step;
	float		hfov2;
	t_coord		cosin;
	float		r_angle;
	t_hit		hit;
	t_sector	*prev;
	t_sector	*sec;
	t_zbuf		*zbuf;
	t_list		*r_secs;
	int			index;

	zbuf = ft_memalloc(sizeof(t_zbuf) * (max - start));
	hfov2 = (float)game->setting->fov / 2;
	step = (float)game->setting->fov / dst->w;
	index = start;
	r_secs = ft_lstnew(&game->map->sectors[game->player->cur_sector], sizeof(t_sector));
	while (index < max)
	{
		angle = (float)index * step;
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
			zbuf[index].dist = hit.og_dist;
			hit.dist *= LEVEL_MULTIPLIER;
			out = draw_vline(&hit, game, index, dst, &out);
			if (out.x != out.y)
			{
				prev = hit.sect;
				sec = hit.wall->window;
				int i = 0;
				while (zbuf[index].bounds[i].sec && i < MAX_OBJ_SECTORS)
					i++;
				zbuf[index].bounds[i] = (t_secbounds){sec, out};
				if (!ft_lstfind_content(r_secs, sec, sizeof(t_sector)))
					ft_lstaddbck(&r_secs, ft_lstnew(sec, sizeof(t_sector)));
			}
		}
		index++;
	}
	render_objects(r_secs, zbuf, dst, game, &(t_coord){
		wrap_float((start * step) + (game->player->angle - hfov2), 0, 360),
		wrap_float((max * step) + (game->player->angle - hfov2), 0, 360)});
	ft_lstdel(&r_secs, NULL);
	ft_memdel((void**)&zbuf);
}

void render_3d(t_game *game, SDL_Surface *dst)
{
	game->player->screen_updown = game->player->updown * dst->h;
	render_chunk(game, dst, 0, dst->w - 1);
}
