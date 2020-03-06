/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_floor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 16:16:04 by ehollidg       #+#    #+#                */
/*   Updated: 2020/03/06 12:15:52 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"
#include "renderer.h"
#include "setting.h"
#include "player.h"
#include "cmath.h"
#include "rinfo.h"
#include "color.h"
#include "game.h"

static void		draw_x(t_rinfo *rin,
					const t_hit *hit, const t_coord fvals, const t_point ivals)
{
	SDL_Surface *srf;
	int			*t_pixels;
	t_coord		vec;
	t_point		tex;
	float		in;
	
	srf = get_texture(rin->game, hit->sect->floor_tex);
	t_pixels = srf->pixels;
	get_vector_from_points((t_coord*)&hit->pos, &rin->game->player->pos, &vec);
	vec = (t_coord){rin->game->player->pos.x - (vec.x * fvals.x),
					rin->game->player->pos.y - (vec.y * fvals.x)};
	tex = (t_point){abs((int)(vec.x * pow(LEVEL_MULTIPLIER, 2))) % srf->w,
					abs((int)(vec.y * pow(LEVEL_MULTIPLIER, 2))) % srf->h};
	in = fvals.y * hit->sect->light_value;
	rin->pixels[(ivals.x + rin->begin) + ((rin->dst->h - ivals.y - 1) *
		rin->dst->w)] =
		rgba_set_intensity(t_pixels[tex.x + (tex.y * srf->w)], in);
}

static void		init_vals(t_rinfo *rin, t_hinfo *info, t_coord *anstep)
{
	float	start;
	int		size;
	float	val;

	info->floor_range.x = ft_constrain(info->floor_range.x, 0, rin->dst->h);
	info->floor_range.y = ft_constrain(info->floor_range.y, 0, rin->dst->h);
	size = info->floor_range.y - info->floor_range.x;
	anstep->y = ((float)size / rin->dst->h) * rin->game->setting->vfov;
	val = ((float)rin->game->player->screen_updown / rin->dst->h) *
		rin->game->setting->vfov;
	if (info->floor_range.x != 0)
		start = ((float)info->floor_range.x / rin->dst->h) *
			rin->game->setting->vfov;
	else
		start = 0;
	anstep->x = 90 + val - rin->vfov2 + start;
	anstep->y /= (float)size;
}

static float	init_height(t_rinfo *rin, t_hinfo *info)
{
	return (rin->game->player->height + rin->game->player->heightoffset -
		info->sec->floor);
}

static void		set_cybounds(t_point *c_ybounds,
											t_point *pre_bound, t_point *ybnds)
{
	c_ybounds->x = ft_constrain(pre_bound->x, 0, ybnds->x);
	c_ybounds->y = ft_constrain(pre_bound->y, c_ybounds->x, ybnds->x);
}

void			draw_floor(t_rinfo *rin, t_hinfo *info)
{
	const float	height = init_height(rin, info);
	t_point	i;
	t_point c_ybounds;
	t_coord disintens;
	t_coord	anstep;

	init_vals(rin, info, &anstep);
	i.y = info->floor_range.x;
	while (i.y < info->floor_range.y)
	{
		i.x = 0;
		disintens.x = (tan(anstep.x * PI_R) * height) * 0.25;
		disintens.y = ((MAX_LIGHT_DIST - clamp_float(disintens.x, 0,
					MAX_LIGHT_DIST)) / MAX_LIGHT_DIST);
		while (i.x < (int)info->size)
		{
			set_cybounds(&c_ybounds, &info->hits[i.x].pre_bound,
				&info->hits[i.x].ybnds);
			if (i.y < c_ybounds.y && i.y >= c_ybounds.x)
				draw_x(rin, &info->hits[i.x].hit, disintens, i);
			i.x++;
		}
		i.y++;
		anstep.x += anstep.y;
	}
}
