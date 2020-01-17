/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_skybox.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/17 18:26:55 by ehollidg       #+#    #+#                */
/*   Updated: 2020/01/17 18:26:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>
#include "libft/ft_num.h"
#include "renderer.h"
#include "setting.h"
#include "player.h"
#include "coord.h"
#include "rinfo.h"
#include "cmath.h"
#include "game.h"

void		draw_skybox(int x,
								SDL_Surface *dst, t_game *game, t_point *bounds)
{
	int			*pixels;
	SDL_Surface	*skybox;
	float		perc;
	int			x_pos;
	int			*skybox_pixels;

	pixels = dst->pixels;
	skybox = get_texture(game, game->map->skybox);
	skybox_pixels = skybox->pixels;
	perc = ((float)game->setting->fov / 360) * skybox->w;
	x_pos = ((perc / dst->w) * x) +
		(wrap_float((float)game->player->angle - (game->setting->fov / 2),
		0, 360) / 360) * skybox->w;
	*bounds = (t_point){ft_constrain(bounds->x, 0, dst->h),
						ft_constrain(bounds->y, 0, dst->h)};
	while (bounds->x < bounds->y)
	{
		pixels[x + ((dst->h - bounds->x - 1) * dst->w)] = skybox_pixels[x_pos +
			(skybox->h - 1 - (int)(((float)bounds->x / dst->h) * skybox->h)) *
			skybox->w];
		bounds->x++;
	}
}
