/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 12:39:17 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/22 15:40:09 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/ft_mem.h"
#include "libft/ft_num.h"
#include "libft/ft_list.h"
#include "game.h"
#include "color.h"
#include "campaign.h"
#include "player.h"
#include "renderer.h"
#include "cmath.h"
#include "rinfo.h"
#include "setting.h"
#include <math.h>
#include "color.h"
#include "error.h"

static void	render_chunk(t_game *game,
									SDL_Surface *dst, size_t start, size_t end)
{
	t_rinfo	rinfo;

	rinfo.hfov2 = (float)game->setting->fov / 2;
	rinfo.vfov2 = (float)game->setting->vfov / 2;
	rinfo.step = (float) game->setting->fov / dst->w;
	rinfo.ren = ft_lstnew(NULL, sizeof(void*));
	rinfo.game = game;
	rinfo.start = start;
	rinfo.end = end;
	rinfo.dst = dst;
	get_hits(&rinfo, tanf(rinfo.vfov2 * PI_R));
	ft_lstrev(&rinfo.ren);
	render_hits(&rinfo, &(t_coord){
		wrap_float((start * rinfo.step) + (game->player->angle - rinfo.hfov2),
		0, 360),
		wrap_float((end * rinfo.step) + (game->player->angle - rinfo.hfov2),
		0, 360)});
}

void		render(t_game *game, SDL_Surface *dst)
{
	game->player->screen_updown = game->player->updown * dst->h;
	render_chunk(game, dst, 0, dst->w - 1);
}
