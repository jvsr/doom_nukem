/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_hits.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:31:45 by euan           #+#    #+#                */
/*   Updated: 2020/03/27 11:04:46 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "renderer.h"
#include "rinfo.h"

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
	if (!info->sec->has_slope)
		draw_floor(rin, info);
	else
		draw_sfloor(rin, info);
	if (info->sec->has_ceiling)
		draw_ceil(rin, info);
}

void			render_hits(t_rinfo *rinfo, t_coord *range)
{
	t_list	*lst;
	t_hinfo	*info;
	size_t	index;
	t_point	bounds;
	t_hitem	*hit;

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
				bounds = info->prev->hits[index - rinfo->begin].pre_bounds;
			if (info->hits[index - rinfo->begin].hit.dist < MAX_HIT)
			{
				hit = info->hits + index - rinfo->begin;
				draw_vline(rinfo, hit, index, &bounds);
				if (hit->ybnds.x > 0 && hit->ybnds.x > info->floor_range.y)
					info->floor_range.y = hit->ybnds.x;
				if (bounds.x < info->floor_range.x)
					info->floor_range.x = bounds.x;
				if (bounds.y > info->ceil_range.y)
					info->ceil_range.y = bounds.y;
				if (hit->ybnds.y > 0 && hit->ybnds.y < info->ceil_range.x)
					info->ceil_range.x = hit->ybnds.y;
			}
				
			index++;
		}
		render_fc(rinfo, info);
		render_objs(rinfo, info, range);
		lst = lst->next;
	}
	ft_lstdel(&rinfo->ren, del_hinfo);
}
