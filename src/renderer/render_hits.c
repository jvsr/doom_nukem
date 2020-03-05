/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_hits.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:31:45 by euan           #+#    #+#                */
/*   Updated: 2020/03/02 10:40:18 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "libft/ft_num.h"
#include "renderer.h"
#include "setting.h"
#include "player.h"
#include "coord.h"
#include "rinfo.h"
#include "cmath.h"
#include "game.h"

static void		del_hinfo(void *info, size_t size)
{
	t_hinfo *h;

	(void)size;
	h = info;
	ft_memdel((void**)&h->hits);
	ft_memdel((void**)&h);
}


static void		render_fc(t_rinfo *rin, t_hinfo *info)
{
	int y;
	int x;
	t_coord ray0;
	t_coord ray1;
	int *pixs = rin->dst->pixels;
	t_point c_ybounds;
	t_point ybnds;
	float	height;
	float	dist;
	float	step;
	float	angle;
	t_coord	vec;
	t_point	tex;
	SDL_Surface	*srf;
	int *t_pixels;
	int size;

	info->floor_range.x = ft_constrain(info->floor_range.x, 0, rin->dst->h);
	info->floor_range.y = ft_constrain(info->floor_range.y, 0, rin->dst->h);
	y = info->floor_range.x;
	height = rin->game->player->height + rin->game->player->heightoffset - info->sec->floor;
	size = info->floor_range.y - info->floor_range.x;
	step = ((float)size / rin->dst->h) * rin->game->setting->vfov;
	float val = ((float)rin->game->player->screen_updown / rin->dst->h) * rin->game->setting->vfov;
	angle = 90 + val - rin->vfov2;
	step /= (float)size;
	while (y < info->floor_range.y)
	{
		x = 0;
		dist = tan(angle * PI_R) * height;
		printf("%f\n", dist);
		while (x < info->size)
		{
			ybnds = info->hits[x].ybnds;
			c_ybounds.x = ft_constrain(info->hits[x].pre_bound.x, 0, ybnds.x);
			c_ybounds.y = ft_constrain(info->hits[x].pre_bound.y, c_ybounds.x, ybnds.x);
			if (y < c_ybounds.y && y >= c_ybounds.x)
			{
				srf = get_texture(rin->game, info->hits[x].hit.sect->floor_tex);
				t_pixels = srf->pixels;
				get_vector_from_points(&info->hits[x].hit.pos, &rin->game->player->pos, &vec);
				vec = (t_coord){rin->game->player->pos.x + (vec.x * dist), rin->game->player->pos.y + (vec.x * dist)};
				tex = (t_point){abs((int)(vec.x * 40)) % srf->w, abs((int)(vec.y * 40)) % srf->h};
				pixs[(x + rin->begin) + ((rin->dst->h - y - 1) * rin->dst->w)] = t_pixels[tex.x + (tex.y * srf->w)];
			}
			x++;
		}
		y++;
		angle += step;
	}
}

void			render_hits(t_rinfo *rinfo, t_coord *range)
{
	t_list	*lst;
	t_hinfo	*info;
	size_t	index;
	t_point	bounds;

	lst = rinfo->ren;
	while (lst)
	{
		info = lst->content;
		index = info->start;
		while (index <= info->end)
		{
			if (lst->next == NULL)
				bounds = (t_point){0, rinfo->dst->h};
			else
				bounds = info->prev->hits[index - rinfo->begin].bounds;
			if (info->hits[index - rinfo->begin].hit.dist < MAX_HIT)
			{
				t_hitem *hit = info->hits + index - rinfo->begin;
				draw_vline(rinfo, hit, index, &bounds);
				if (hit->ybnds.x > 0 && hit->ybnds.x > info->floor_range.y)
					info->floor_range.y = hit->ybnds.x;
				if (bounds.x < info->floor_range.x)
					info->floor_range.x = bounds.x;
			}
				
			index++;
		}
		render_fc(rinfo, info);
		render_objs(rinfo, info, range);
		lst = lst->next;
	}
	ft_lstdel(&rinfo->ren, del_hinfo);
}
