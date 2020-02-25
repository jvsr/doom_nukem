/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_hits.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 15:53:58 by euan           #+#    #+#                */
/*   Updated: 2020/02/22 15:29:29 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_list.h"
#include "player.h"
#include "renderer.h"
#include "cmath.h"
#include "coord.h"
#include "rinfo.h"
#include "error.h"
#include "game.h"

static t_hinfo	*new_hinfo(t_sector *sec, size_t ar_size, size_t start)
{
	t_hinfo *info;

	info = ft_memalloc(sizeof(t_hinfo));
	if (info == NULL)
		error_msg_errno("Error allocating hinfo");
	info->sec = sec;
	info->hits = (t_hitem*)ft_memalloc(sizeof(t_hitem) * ar_size);
	if (info->hits == NULL)
		error_msg_errno("Error allocating hinfo hits");
	info->size = ar_size;
	info->start = start;
	return (info);
}

static void		move_sector(t_hit *hit,
								t_hinfo **prev, t_hinfo **info, t_rinfo *rinfo)
{
	t_list	*tmp;
	t_hinfo	*htmp;

	*prev = *info;
	tmp = rinfo->ren;
	while (tmp)
	{
		htmp = tmp->content;
		if (hit->wall->window == htmp->sec)
		{
			*info = htmp;
			return ;
		}
		tmp = tmp->next;
	}
	ft_lstaddbck(&rinfo->ren, ft_lstnew(new_hinfo(hit->wall->window,
		(*info)->size, rinfo->start), sizeof(t_hinfo)));
	*info = ft_lstlast(rinfo->ren)->content;
}

static t_bool	hit_meth(t_hitem *hit,
									t_rinfo *rinfo, float angle, t_point *tmp)
{
	if (hit->hit.dist == MAX_HIT)
	{
		tmp->y = tmp->x;
		return (TRUE);
	}
	if (angle > rinfo->hfov2)
		hit->hit.dist *= cosf((angle - rinfo->hfov2) * PI_R);
	else if (angle < rinfo->hfov2)
		hit->hit.dist *= cosf((rinfo->hfov2 - angle) * PI_R);
	hit->hit.og_dist = hit->hit.dist;
	hit->hit.dist *= LEVEL_MULTIPLIER;
	return (FALSE);
}

static void		hit(t_rinfo *rinfo, t_coord *cosin, float angle, float tanvfov2)
{
	t_hitem	*hit;
	t_hinfo *info;
	t_hinfo	*prev;
	t_point	tmp;

	info = rinfo->ren->content;
	prev = info;
	tmp = (t_point){0, rinfo->dst->h};
	hit = NULL;
	while (tmp.x != tmp.y && (hit == NULL || hit->hit.wall->is_portal))
	{
		info->prev = prev;
		info->end = rinfo->start;
		hit = info->hits + rinfo->start - rinfo->begin;
		hit->hit = get_hit(cosin, rinfo->game->player, info->sec, prev->sec);
		if (hit_meth(hit, rinfo, angle, &tmp))
			continue;
		tmp = get_bounds(rinfo->game->player, rinfo->dst, hit, tanvfov2);
		hit->bounds = tmp;
		if (tmp.x != tmp.y && hit->hit.wall->is_portal == TRUE)
			move_sector(&hit->hit, &prev, &info, rinfo);
	}
}

void			get_hits(t_rinfo *rinfo, float tanvfov2)
{
	float	angle;
	float	r_angle;
	t_coord	cosin;

	rinfo->begin = rinfo->start;
	rinfo->ren->content = new_hinfo(rinfo->game->map->sectors +
		rinfo->game->player->cur_sector, rinfo->end - rinfo->start,
		rinfo->start);
	// printf("%zu : %zu\n", rinfo->start, rinfo->end);
	while (rinfo->start < rinfo->end)
	{
		angle = rinfo->step * rinfo->start;
		r_angle = wrap_float(angle + (rinfo->game->player->angle -
			rinfo->hfov2), 0, 360) * PI_R;
		cosin = (t_coord){cosf(r_angle), sinf(r_angle)};
		hit(rinfo, &cosin, angle, tanvfov2);
		rinfo->start++;
	}
}
