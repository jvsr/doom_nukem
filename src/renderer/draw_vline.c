/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_vline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:35:04 by euan          #+#    #+#                 */
/*   Updated: 2020/04/09 15:43:37 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_num.h"
#include "renderer.h"
#include "player.h"
#include "cmath.h"
#include "color.h"
#include "coord.h"
#include "rinfo.h"
#include "game.h"

static t_hinfo	*find_hinfo(t_list *lst, t_sector *sec)
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

static void		draw_portal(t_rinfo *rinfo,
								t_hitem *item, size_t index, SDL_Point **bounds)
{
	SDL_Point	nybnds;

	nybnds = (find_hinfo(rinfo->ren, item->hit.sect))->hits[index -
				rinfo->begin].bounds;
	if (nybnds.x > 0)
		draw_wall(rinfo, (SDL_Point*[2]){*bounds, &(SDL_Point){bounds[1]->x,
			nybnds.x}}, index, &item->hit);
	if (nybnds.y < rinfo->dst->h)
		draw_wall(rinfo, (SDL_Point*[2]){*bounds, &(SDL_Point){nybnds.y,
			bounds[1]->y}}, index, &item->hit);
	if (item->hit.wall->is_window && nybnds.x < bounds[1]->x)
		draw_glass(rinfo,
			(SDL_Point*[2]){*bounds, bounds[1]}, index, &item->hit);
	else if (item->hit.wall->is_window)
		draw_glass(rinfo, (SDL_Point*[2]){*bounds, &nybnds}, index,
			&item->hit);
}

void			draw_vline(t_rinfo *rinfo,
								t_hitem *item, size_t index, SDL_Point *bounds)
{
	if (item == NULL || item->hit.sect == NULL)
		return ;
	item->ybnds.x = ((item->hit.sect->floor - item->y.x) / item->st.x) *
				(rinfo->dst->h) - rinfo->game->player->screen_updown;
	item->ybnds.y = rinfo->dst->h - (((item->y.y - item->hit.sect->ceil) /
		item->st.x) * (rinfo->dst->h)) - rinfo->game->player->screen_updown;
	if (item->hit.sect->has_slope == TRUE && item->hit.wall !=
		item->hit.sect->swall)
	{
		item->ybnds.x -= get_slope(item, item->hit.sect->swall,
			item->hit.sect->angle, rinfo);
		item->ybnds.x += (item->hit.sect->floor / item->st.x) * rinfo->dst->h;
	}
	if (item->ybnds.y < rinfo->dst->h && !item->hit.sect->has_ceiling)
		draw_skybox(index, rinfo->dst, rinfo->game,
			(SDL_Point[2]){(SDL_Point){item->ybnds.y, rinfo->dst->h}, *bounds});
	if (!item->hit.wall->is_portal)
		draw_wall(rinfo,
					(SDL_Point*[2]){bounds, &item->ybnds}, index, &item->hit);
	if (item->hit.wall->is_portal &&
		item->hit.sect->ceil > item->y.x && item->hit.sect->floor < item->y.y)
		draw_portal(rinfo, item, index, (SDL_Point*[2]){bounds, &item->ybnds});
}
