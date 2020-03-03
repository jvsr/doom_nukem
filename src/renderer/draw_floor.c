/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_floor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 16:16:04 by ehollidg       #+#    #+#                */
/*   Updated: 2020/03/02 18:54:25 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"
#include "renderer.h"
#include "player.h"
#include "cmath.h"
#include "game.h"

static int	get_tex(t_hit *hit, t_player *player, int y, SDL_Surface *tex, t_rinfo *rin, int val)
{
	float		dist;
	const int	*t_pixels = tex->pixels;
	t_coord		vec;

	dist = (rin->dst->h) / (2.0 * (y + player->screen_updown) - (rin->dst->h));
	vec.x = (dist / hit->og_dist) * hit->pos.x + (1.0 - (dist / hit->og_dist)) * player->pos.x;
	vec.y = (dist / hit->og_dist) * hit->pos.y + (1.0 - (dist / hit->og_dist)) * player->pos.y;
	int x = (int)fabs(vec.x * 20) % tex->w;
	int y0 = (int)fabs(vec.y * 20) % tex->h;
	return (t_pixels[x + (y0 * tex->w)]);
}

void		draw_floor(t_rinfo *rinfo, t_point **bounds, const size_t index, t_hitem *hit)
{
	int		*pixels;
	int		i;
	t_point	c_ybounds;

	pixels = rinfo->dst->pixels;
	if (index >= (size_t)rinfo->dst->w)
		return ;
	*bounds[0] = (t_point){ft_constrain(bounds[0]->x, 0, rinfo->dst->h),
					ft_constrain(bounds[0]->y, 0, rinfo->dst->h)};
	c_ybounds.x = ft_constrain(bounds[1]->x, bounds[0]->x, bounds[0]->y);
	c_ybounds.y = ft_constrain(bounds[1]->y, c_ybounds.x, bounds[0]->y);
	i = c_ybounds.x;
	while (i < c_ybounds.y)
	{
		pixels[index + (rinfo->dst->w * (rinfo->dst->h - i - 1))] = get_tex(&hit->hit,
			rinfo->game->player, i, get_texture(rinfo->game,
			hit->hit.sect->floor_tex), rinfo, c_ybounds.y);
		i++;
	}
}
