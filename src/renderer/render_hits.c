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
#include "renderer.h"
#include "coord.h"
#include "rinfo.h"

static void		del_hinfo(void *info, size_t size)
{
	t_hinfo *h;

	(void)size;
	h = info;
	ft_memdel((void**)&h->hits);
	ft_memdel((void**)&h);
}

/*
static t_point	find_bounds_floor(t_rinfo *rinfo, t_hinfo *hinfo)
{
	size_t	i;
	t_point	bnds;

	i = 0;
	bnds = (t_point){INT32_MAX, 0};
	while (i + rinfo->begin < hinfo->end)
	{
		if (hinfo->prev == NULL)
			bnds.x = 0;
		else if (hinfo->prev->hits[i].bounds.x < bnds.x)
			bnds.x = hinfo->prev->hits[i].bounds.x;
		if (hinfo->hits[i].ybnds.x > bnds.y)
			bnds.y = hinfo->hits[i].ybnds.x;
		i++;
	}
	return (bnds);
}
*/

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
				draw_vline(rinfo, info->hits + index - rinfo->begin,
					index, &bounds);
			index++;
		}
		render_objs(rinfo, info, range);
		lst = lst->next;
	}
	ft_lstdel(&rinfo->ren, del_hinfo);
}
