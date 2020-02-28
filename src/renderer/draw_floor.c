/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_floor.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 16:16:04 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/27 16:16:04 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_num.h"
#include "renderer.h"
#include "player.h"
#include "cmath.h"
#include "game.h"

static int	get_tex(t_hit *hit, t_player *player, t_point *bounds, int y, SDL_Surface *tex, int h2)
{
	float		dist;
	t_coord		pos;
	const int	*t_pixels = tex->pixels;

	dist = (float)(y + player->screen_updown) / ((bounds->y + player->screen_updown) - (bounds->x+ player->screen_updown));
	dist *= hit->og_dist;
	// printf("Dist %f\n", dist);
	pos.x = fabs(player->pos.x + dist * (hit->pos.x - player->pos.x));
	pos.y = fabs(player->pos.y + dist * (hit->pos.y - player->pos.y));
	printf("Pos %f, %f\n", pos.x, pos.y);
	int x = (tex->w * (((int)pos.y) % tex->h));
	int j = ((int)pos.x % tex->w);
	return (t_pixels[j + x]);
}

void		draw_floor(t_rinfo *rinfo, t_point **bounds, const size_t index, t_hit *hit)
{
	int		*pixels;
	int		i;
	t_point	c_ybounds;
	int		h2;

	h2 = rinfo->dst->h / 2;
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
		pixels[index + (rinfo->dst->w * (rinfo->dst->h - i - 1))] = get_tex(hit,
			rinfo->game->player, bounds[0], i, get_texture(rinfo->game,
			hit->sect->floor_tex), h2);
		i++;
	}
}
