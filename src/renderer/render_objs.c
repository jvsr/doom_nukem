/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_objs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:39:30 by euan           #+#    #+#                */
/*   Updated: 2020/02/22 15:44:54 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_num.h"
#include "renderer.h"
#include "player.h"
#include "cmath.h"
#include "coord.h"
#include "color.h"
#include "rinfo.h"
#include "game.h"

static void draw_object(t_list *objs,
								SDL_Surface *dst, t_game *game, t_hinfo *info)
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

static void	check_obj(const float objang,
							const t_coord *range, t_rinfo *rinfo, t_oinfo *oi)
{
	const float	tmpang = calc_fov(range->x, objang);
	int			scrnspc;
	float		dist;

	oi->obj->img.angle = objang;
	scrnspc = (int)((tmpang / calc_fov(range->x, range->y)) * rinfo->dst->w);
	dist = get_distance(&rinfo->game->player->pos, &oi->obj->pos);
	if (tmpang > rinfo->hfov2)
		dist *= cosf((tmpang - rinfo->hfov2) * PI_R);
	else if (tmpang < rinfo->hfov2)
		dist *= cosf((rinfo->hfov2 - tmpang) * PI_R);
	if (dist < oi->info->hits[scrnspc].hit.og_dist)
		ft_lstadd(oi->objs, ft_lstnew(new_rendobj(oi->obj, oi->info->sec,
			(float[2]){dist, objang}, scrnspc), sizeof(t_objrend)));
}

void render_objs(t_rinfo *rinfo, t_hinfo *info, t_coord *range)
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
			check_obj(objang, range, rinfo, &(t_oinfo){obj, &objs, info});
		tmp = tmp->next;
	}
	ft_lstsort(&objs, sort_objs);
	draw_object(objs, rinfo->dst, rinfo->game, info);
	ft_lstdel(&objs, NULL);
}
