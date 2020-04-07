/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_hits.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/21 15:53:58 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:29:27 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "libft/ft_num.h"
#include "renderer.h"
#include "player.h"
#include "cmath.h"
#include "coord.h"
#include "rinfo.h"
#include "error.h"
#include "game.h"

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
									t_rinfo *rinfo, float angle, SDL_Point *tmp)
{
	if (hit->hit.dist == MAX_HIT)
	{
		tmp->y = tmp->x;
		return (TRUE);
	}
	if (angle > rinfo->hfov2)
	{
		hit->hit.angle = angle - rinfo->hfov2;
		hit->hit.dist *= cosf(hit->hit.angle * PI_R);
	}
	else if (angle < rinfo->hfov2)
	{
		hit->hit.angle = rinfo->hfov2 - angle;
		hit->hit.dist *= cosf(hit->hit.angle * PI_R);
	}
	hit->hit.og_dist = hit->hit.dist;
	hit->hit.dist *= LEVEL_MULTIPLIER;
	return (FALSE);
}

static void		hit_end(t_hitem *hit,
							t_rinfo *rinfo, SDL_Point **points, t_hinfo ***ins)
{
	if (hit->hit.wall->window && hit->hit.wall->window->has_slope)
		points[0]->x -= get_slope(hit, hit->hit.wall->window->swall,
			hit->hit.wall->window->angle, rinfo);
	hit->bounds = *points[0];
	hit->pre_bounds = *points[1];
	*points[1] = *points[0];
	if (points[0]->x != points[0]->y && hit->hit.wall->is_portal == TRUE)
		move_sector(&hit->hit, ins[1], ins[0], rinfo);
}

static void		hit(t_rinfo *rinfo, t_coord *cosin, float angle, float tanvfov2)
{
	t_hitem		*hit;
	t_hinfo		*info;
	t_hinfo		*prev;
	SDL_Point	tmp;
	SDL_Point	prv;

	info = rinfo->ren->content;
	prev = info;
	tmp = (SDL_Point){0, rinfo->dst->h};
	hit = NULL;
	prv = tmp;
	while (tmp.x != tmp.y && (hit == NULL || hit->hit.wall->is_portal))
	{
		info->prev = prev;
		info->floor_range = (SDL_Point){INT32_MAX, 0};
		info->ceil_range = (SDL_Point){INT32_MAX, 0};
		info->end = rinfo->start;
		hit = info->hits + rinfo->start - rinfo->begin;
		hit->hit = get_hit(cosin, rinfo->game->player, info->sec, prev->sec);
		if (hit_meth(hit, rinfo, angle, &tmp))
			continue;
		tmp = get_bounds(rinfo->game->player, rinfo->dst, hit, tanvfov2);
		hit_end(hit, rinfo, (SDL_Point*[2]){&tmp, &prv},
			(t_hinfo**[2]){&info, &prev});
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
