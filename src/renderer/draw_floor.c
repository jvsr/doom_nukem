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

static int	get_tex(t_hit *hit, t_player *player, int y, SDL_Surface *tex, t_game *game, int offset)
{
	float		dist;
	t_coord		pos;
	const int	*t_pixels = tex->pixels;
	t_coord		vec;

	dist = game->ftable.table[(y + player->screen_updown) + offset];
	dist *= (90 + player->heightoffset) * cosf(hit->angle * PI_R);
	get_vector_from_points(&player->pos, &hit->pos, &vec);
	dist /= hit->og_dist;
	pos.x = player->pos.x + dist * (hit->pos.x - player->pos.x);
	pos.y = player->pos.y + dist * (hit->pos.y - player->pos.y);
	if (hit->angle == 0)
		printf("Pos (%f, %f), Dist %f, Hit (%f, %f)\n", pos.x, pos.y, dist, hit->pos.x, hit->pos.y);
	int x = abs((int)(pos.y * 4)) % tex->h;
	int j = abs((int)(pos.x * 4)) % tex->w;
	return (t_pixels[j + (x * tex->w)]);
}

void		draw_floor(t_rinfo *rinfo, t_point **bounds, const size_t index, t_hit *hit)
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
		pixels[index + (rinfo->dst->w * (rinfo->dst->h - i - 1))] = get_tex(hit,
			rinfo->game->player, i, get_texture(rinfo->game,
			hit->sect->floor_tex), rinfo->game, fabs(PLAYER_UPDOWN_MIN * rinfo->dst->h));
		i++;
	}
}
