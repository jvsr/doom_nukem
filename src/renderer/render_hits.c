/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_hits.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:31:45 by euan           #+#    #+#                */
/*   Updated: 2020/03/04 12:23:44 by jvisser       ########   odam.nl         */
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

void			render_hits(t_rinfo *rinfo, t_coord *range)
{
	t_list		*lst;
	t_hinfo		*info;
	size_t		index;
	SDL_Point	bounds;

	lst = rinfo->ren;
	while (lst)
	{
		info = lst->content;
		index = info->start;
		while (index <= info->end)
		{
			if (lst->next == NULL)
				bounds = (SDL_Point){0, rinfo->dst->h};
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
