/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_skybox.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 18:26:55 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:09:03 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include "libft/ft_num.h"
#include "textures.h"
#include "renderer.h"
#include "setting.h"
#include "player.h"
#include "coord.h"
#include "rinfo.h"
#include "cmath.h"
#include "game.h"

void		draw_skybox(size_t x,
							SDL_Surface *dst, t_game *game, SDL_Point *bounds)
{
	int					*pixels;
	SDL_Surface const	*skybox = get_texture(game, game->map->skybox);
	int					x_pos;
	int					*skybox_pixels;
	SDL_Point			change;

	change.x = fabs(dst->h * PLAYER_UPDOWN_MIN);
	change.y = fabs(dst->h * PLAYER_UPDOWN_MAX);
	pixels = dst->pixels;
	skybox_pixels = skybox->pixels;
	x_pos = (((((float)game->setting->fov / 360) * skybox->w) / dst->w) * x) +
		(wrap_float((float)game->player->angle - (game->setting->fov / 2),
		0, 360) / 360) * skybox->w;
	bounds[1] = (SDL_Point){ft_constrain(bounds[1].x, 0, dst->h),
				ft_constrain(bounds[1].y, 0, dst->h)};
	bounds->x = ft_constrain(bounds->x, bounds[1].x, bounds[1].y);
	bounds->y = ft_constrain(bounds->y, bounds->x, bounds[1].y);
	while (bounds->x < bounds->y)
	{
		pixels[x + ((dst->h - bounds->x - 1) * dst->w)] = skybox_pixels[x_pos +
			(skybox->h - 1 - (int)(((float)(bounds->x + change.x +
			game->player->screen_updown) / (dst->h + change.x + change.y)) *
			skybox->h)) * skybox->w];
		bounds->x++;
	}
}
