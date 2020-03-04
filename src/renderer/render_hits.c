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
#include "coord.h"
#include "rinfo.h"
#include "cmath.h"

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

	info->floor_range.x = ft_constrain(info->floor_range.x, 0, rin->dst->h);
	info->floor_range.y = ft_constrain(info->floor_range.y, 0, rin->dst->h);
	y = info->floor_range.x;
	while (y < info->floor_range.y)
	{
		x = 0;
		while (x < info->size)
		{
			ybnds = info->hits[x].ybnds;
			c_ybounds.x = ft_constrain(info->hits[x].pre_bound.x, 0, ybnds.x);
			c_ybounds.y = ft_constrain(info->hits[x].pre_bound.y, c_ybounds.x, ybnds.x);
			if (y < c_ybounds.y && y >= c_ybounds.x)
				pixs[(x + rin->begin) + ((rin->dst->h - y - 1) * rin->dst->w)] = FLOOR_COLOR;
			x++;
		}
		y++;
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
