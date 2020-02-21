/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 12:39:17 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/21 16:00:02 by euan          ########   odam.nl         */
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
#include "error.h"
#include "personal.h"

static void		del_hinfo(void *info, size_t size)
{
	t_hinfo *h;

	(void)size;
	h = info;
	ft_memdel((void**)&h->hits);
	ft_memdel((void**)&h);
}

static void draw_cline(SDL_Surface *dst, t_point *ybounds, size_t index, int colour, t_point *bounds)
{
	int *pixels;
	int i;
	t_point c_ybounds;

	pixels = dst->pixels;
	if (index >= (size_t)dst->w)
		return;
	*bounds = (t_point){ft_constrain(bounds->x, 0, dst->h), ft_constrain(bounds->y, 0, dst->h)};
	c_ybounds.x = ft_constrain(ybounds->x, bounds->x, bounds->y);
	c_ybounds.y = ft_constrain(ybounds->y, c_ybounds.x, bounds->y);
	i = c_ybounds.x;
	if (colour != -1)
	{
		while (i < c_ybounds.y)
		{
			pixels[index + (dst->w * (dst->h - i - 1))] = colour;
			i++;
		}
	}
}

static void draw_wall(SDL_Surface *dst, t_point *ybounds, size_t x, t_point *bounds, t_hit *hit, t_game *game)
{
	int *pixels;
	int i;
	t_point c_ybounds;
	t_bool check;
	t_list *decals;

	pixels = dst->pixels;
	decals = NULL;
	if (x >= (size_t)dst->w)
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

static void draw_glass(SDL_Surface *dst, t_point *ybounds, size_t x, t_point *bounds, t_hit *hit, t_game *game)
{
	int *pixels;
	int i;
	t_point c_ybounds;
	t_bool check;
	t_list *decals;

	pixels = dst->pixels;
	decals = NULL;
	if (x >= (size_t)dst->w)
		return;
	*bounds = (t_point){ft_constrain(bounds->x, 0, dst->h), ft_constrain(bounds->y, 0, dst->h)};
	c_ybounds.x = ft_constrain(ybounds->x, bounds->x, bounds->y);
	c_ybounds.y = ft_constrain(ybounds->y, c_ybounds.x, bounds->y);
	i = c_ybounds.x;
	SDL_Surface *tex = tex_from_anim(game, &hit->wall->win_tex);
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
			int val = x + (dst->w * (dst->h - i - 1));
			pixels[val] = mix_color(pixels[val], rgba_intensity(t_pixels[(y * tex->w) + tex_x], intensity));
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
			int val = x + (dst->w * (dst->h - i - 1));
			pixels[val] = mix_color(pixels[val], rgba_intensity(colour, intensity));
			i++;
		}
		ft_lstdel(&decals, NULL);
	}
}

static t_hinfo *find_hinfo(t_list *lst, t_sector *sec)
{
	t_hinfo *info;

	while (lst != NULL)
	{
		info = lst->content;
		if (sec == info->sec)
			return (info);
		lst = lst->next;
	}
	return (NULL);
}

static void	draw_vline(t_game *game, SDL_Surface *dst, t_hitem *item, size_t index, t_list *ren, t_point *bounds)
{
	t_point	ybnds;
	t_point	nybnds;

	if (item == NULL || item->hit.sect == NULL)
		return ;
	ybnds.x = ((item->hit.sect->floor - item->y.x) / item->st.x) * (dst->h) - game->player->screen_updown;
	ybnds.y =dst->h - (((item->y.y - item->hit.sect->ceil) / item->st.x) * (dst->h)) - game->player->screen_updown;
	if (ybnds.y < dst->h && item->hit.sect->has_ceiling)
		draw_cline(dst, &(t_point){ybnds.y, dst->h}, index, CEILING_COLOR,
			bounds);
	else if (ybnds.y < dst->h)
		draw_skybox(index, dst, game,
			(t_point[2]){(t_point){ybnds.y, dst->h}, *bounds});
	if (ybnds.x > 0)
		draw_cline(dst, &(t_point){0, ybnds.x}, index, FLOOR_COLOR,
			bounds);
	if (!item->hit.wall->is_portal && item->hit.sect->ceil > item->y.x &&
			item->hit.sect->floor < item->y.y)
		draw_wall(dst, &ybnds, index, bounds, &item->hit, game);
	else if (item->hit.sect->ceil > item->y.x &&
				item->hit.sect->floor < item->y.y)
	{
		nybnds = (find_hinfo(ren, item->hit.sect))->hits[index].bounds;
		if (nybnds.x > 0)
			draw_wall(dst, &(t_point){ybnds.x, nybnds.x}, index,
				bounds, &item->hit, game);
		if (nybnds.y < dst->h)
			draw_wall(dst, &(t_point){nybnds.y, ybnds.y}, index,
				bounds, &item->hit, game);
		if (item->hit.wall->is_window && nybnds.x < ybnds.x)
			draw_glass(dst, &ybnds, index, bounds, &item->hit, game);
		else if (item->hit.wall->is_window)
			draw_glass(dst, &nybnds, index, bounds, &item->hit, game);
	}
}

static void	check_obj(t_object *obj, float objang, t_list **objs, t_coord *range, t_hinfo *info, t_rinfo *rinfo)
{
	float	tmpang;
	int		scrnspc;
	float	dist;

	obj->img.angle = objang;
	tmpang = calc_fov(range->x, objang);
	scrnspc = (int)((tmpang / calc_fov(range->x, range->y)) * rinfo->dst->w);
	dist = get_distance(&rinfo->game->player->pos, &obj->pos);
	if (tmpang > rinfo->hfov2)
		dist *= cosf((tmpang - rinfo->hfov2) * PI_R);
	else if (tmpang < rinfo->hfov2)
		dist *= cosf((rinfo->hfov2 - tmpang) * PI_R);
	if (dist < info->hits[scrnspc].hit.og_dist)
		ft_lstadd(objs, ft_lstnew(new_rendobj(obj, info->sec,
			(float[2]){dist, objang}, scrnspc), sizeof(t_objrend)));
}

static void draw_object(t_list *objs, SDL_Surface *dst, t_game *game, t_hinfo *info)
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
			if (x >= 0 && x < dst->w && obj->dist < info->hits[x].hit.dist)
			{
				c_ybounds = set_ybounds(obj, game, (t_ybinfo){dst->h, &ybounds, x, info->prev});
				int *t_pixels = tex->pixels;
				float perc = (float)(x - xbounds.x) / (xbounds.y - xbounds.x);
				int tex_x = perc * (tex->w - 1);
				float intensity = ((MAX_LIGHT_DIST - clamp_float(obj->dist, 0, MAX_LIGHT_DIST)) / MAX_LIGHT_DIST) * obj->sec->light_value;
				int i = c_ybounds.x;
				if (i < 0)
					i = 0;
				if (c_ybounds.y >= dst->h)
					c_ybounds.y = dst->h - 1;
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

static void render_objs(t_rinfo *rinfo, t_hinfo *info, t_coord *range)
{
	t_list		*objs;
	float		objang;
	t_object	*obj;
	t_list		*tmp;

	objs = NULL;
	tmp = info->sec->objects;
	while (tmp)
	{
		obj = tmp->content;
		objang = get_object_angle_on_screen(obj, rinfo->game->player, range);
		if (objang >= 0)
			check_obj(obj, objang, &objs, range, info, rinfo);
		tmp = tmp->next;
	}
	ft_lstsort(&objs, sort_objs);
	draw_object(objs, rinfo->dst, rinfo->game, info);
	ft_lstdel(&objs, NULL);
}

static void	render_hits(t_rinfo *rinfo, t_coord *range)
{
	t_list	*lst;
	t_hinfo	*info;
	size_t	index;
	t_point	bounds;

	info = NULL;
	lst = rinfo->ren;
	while (lst)
	{
		info = lst->content;
		index = info->start;
		while (index < info->end)
		{
			if (lst->next == NULL)
				bounds = (t_point){0, rinfo->dst->h};
			else
				bounds = info->prev->hits[index].bounds;
			if (info->hits[index].hit.dist < MAX_HIT)
				draw_vline(rinfo->game, rinfo->dst, info->hits + index, index, rinfo->ren, &bounds);
			index++;
		}
		render_objs(rinfo, info, range);
		lst = lst->next;
	}
	ft_lstdel(&rinfo->ren, del_hinfo);
}

static void render_chunk(t_game *game, SDL_Surface *dst, size_t start, size_t end)
{
	t_rinfo	rinfo;

	rinfo.hfov2 = (float)game->setting->fov / 2;
	rinfo.vfov2 = (float)game->setting->vfov / 2;
	rinfo.step = (float) game->setting->fov / dst->w;
	rinfo.ren = ft_lstnew(NULL, sizeof(void*));
	rinfo.game = game;
	rinfo.start = start;
	rinfo.end = end;
	rinfo.dst = dst;
	get_hits(&rinfo, tanf(rinfo.vfov2 * PI_R));
	ft_lstrev(&rinfo.ren);
	render_hits(&rinfo, &(t_coord){
		wrap_float((start * rinfo.step) + (game->player->angle - rinfo.hfov2), 0, 360),
		wrap_float((end * rinfo.step) + (game->player->angle - rinfo.hfov2), 0, 360)});
}

void	render(t_game *game, SDL_Surface *dst)
{
	game->player->screen_updown = game->player->updown * dst->h;
	render_chunk(game, dst, 0, dst->w - 1);
}
