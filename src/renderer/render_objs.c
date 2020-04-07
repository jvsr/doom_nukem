/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render_objs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:39:30 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:04:18 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_num.h"
#include "textures.h"
#include "renderer.h"
#include "player.h"
#include "cmath.h"
#include "coord.h"
#include "color.h"
#include "rinfo.h"
#include "game.h"

static void	check_obj(const float objang,
							const t_coord *range, t_rinfo *rinfo, t_oinfo *oi)
{
	const float	tmpang = calc_fov(range->x, objang);
	int			scrnspc;
	float		dist;

	oi->obj->img.angle = objang;
	scrnspc = (int)((tmpang / calc_fov(range->x, range->y)) * rinfo->dst->w);
	dist = get_distance(&rinfo->game->player->pos, &oi->obj->pos);
	if (tmpang > rinfo->hfov2)
		dist *= cosf((tmpang - rinfo->hfov2) * PI_R);
	else if (tmpang < rinfo->hfov2)
		dist *= cosf((rinfo->hfov2 - tmpang) * PI_R);
	if (dist < oi->info->hits[ft_constrain((size_t)scrnspc, 0, rinfo->end -
		rinfo->begin - 1)].hit.og_dist)
		ft_lstadd(oi->objs, ft_lstnew(new_rendobj(oi->obj, oi->info->sec,
			(float[2]){dist, objang}, scrnspc), sizeof(t_objrend)));
}

void		render_objs(t_rinfo *rinfo, t_hinfo *info, t_coord *range)
{
	t_list		*objs;
	float		objang;
	t_object	*obj;
	t_list		*tmp;

	objs = NULL;
	tmp = info->sec->objects;
	while (tmp)
	{
		obj = tmp->content;
		objang = get_object_angle_on_screen(obj, rinfo->game->player, range);
		if (objang >= 0)
			check_obj(objang, range, rinfo, &(t_oinfo){obj, &objs, info});
		tmp = tmp->next;
	}
	ft_lstsort(&objs, sort_objs);
	draw_object(objs, rinfo, info);
	ft_lstdel(&objs, ft_lstdelmem);
}
