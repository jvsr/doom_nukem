/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_obj.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/25 10:44:13 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/13 13:41:31 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "libft/ft_num.h"
#include "textures.h"
#include "renderer.h"
#include "player.h"
#include "coord.h"
#include "rinfo.h"
#include "cmath.h"
#include "color.h"
#include "game.h"

static void			calc_perinten(float *perc,
					float *intensity, const t_odraw *ob, const t_orend *oren)
{
	*perc = (float)(ob->x - oren->xbounds.x) / (oren->xbounds.y -
		oren->xbounds.x);
	*intensity = ((MAX_LIGHT_DIST - clamp_float(ob->obj->dist, 0,
		MAX_LIGHT_DIST)) / MAX_LIGHT_DIST) * ob->obj->sec->light_value;
}

static void			draw_y(const t_orend *oren, t_odraw *ob,
											const int *t_pixels, int *pixels)
{
	SDL_Point	c_ybounds;
	float		perc;
	float		intensity;
	int			vals[5];

	c_ybounds = set_ybounds(ob->obj, ob->game, (t_ybinfo){ob->dst->h,
		(SDL_Point*)&oren->ybounds, ob->x - ob->rinfo->begin, ob->info->prev});
	calc_perinten(&perc, &intensity, ob, oren);
	vals[0] = perc * (ob->tex->w - 1);
	vals[1] = c_ybounds.x;
	if (vals[1] < 0)
		vals[1] = 0;
	if (c_ybounds.y >= ob->dst->h)
		c_ybounds.y = ob->dst->h - 1;
	while (vals[1] < c_ybounds.y)
	{
		vals[2] = (float)(vals[1] - oren->ybounds.x) / (oren->ybounds.y -
			oren->ybounds.x) * ob->tex->h;
		vals[3] = t_pixels[((ob->tex->h - vals[2] - 1) * ob->tex->w) + vals[0]];
		vals[4] = ob->x + (ob->dst->w * (ob->dst->h - vals[1] - 1));
		if (vals[3] != 0)
			pixels[vals[4]] = mix_color(pixels[vals[4]],
				rgba_set_intensity(vals[3], intensity));
		vals[1]++;
	}
}

static SDL_Point	calc_ybounds(const t_objrend *obj, const SDL_Surface *dst,
										const t_game *game, const t_orend *oren)
{
	return ((SDL_Point){(((obj->sec->floor - oren->y.x) / oren->st.x) *
		(dst->h)) - game->player->screen_updown, dst->h - (((oren->y.y -
		(obj->obj->size.y + obj->sec->floor)) / oren->st.x) * (dst->h)) -
		game->player->screen_updown});
}

static void			loop_objs(t_objrend *obj,
								t_rinfo *rin, t_hinfo *info, const t_coord size)
{
	t_orend			oren;
	size_t			x;
	SDL_Surface		*tex;

	oren.st.y = obj->dist;
	oren.y.x = rin->game->player->height + rin->game->player->heightoffset;
	oren.y.y = oren.y.x + oren.st.y;
	oren.y.x -= oren.st.y;
	oren.st.x = oren.st.y * 2;
	oren.ybounds = calc_ybounds(obj, rin->dst, rin->game, &oren);
	oren.diff = (abs(oren.ybounds.y - oren.ybounds.x) * (size.x / size.y)) / 2;
	oren.xbounds = (SDL_Point){obj->x - oren.diff, obj->x + oren.diff};
	ft_memcpy(&obj->obj->ssize, &oren.xbounds, sizeof(SDL_Point));
	oren.c_xbounds.x = ft_constrain(oren.xbounds.x, rin->begin, rin->end);
	oren.c_xbounds.y = ft_constrain(oren.xbounds.y, oren.c_xbounds.x, rin->end);
	x = oren.c_xbounds.x;
	tex = sdl_from_anim(rin->game, &obj->obj->img);
	while (x < (size_t)oren.c_xbounds.y)
	{
		if (x >= rin->begin && x < rin->end && obj->dist <
			info->hits[x - rin->begin].hit.dist)
			draw_y(&oren, &((t_odraw){rin->game, rin->dst, tex, obj, info, x,
				rin}), tex->pixels, rin->dst->pixels);
		x++;
	}
}

void				draw_object(t_list *objs, t_rinfo *rinfo, t_hinfo *info)
{
	t_objrend *obj;

	while (objs)
	{
		obj = objs->content;
		loop_objs(obj, rinfo, info, obj->obj->size);
		objs = objs->next;
	}
}
