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
#include "sdl_thread.h"
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

static void	*render_chunk(t_game *game,
									SDL_Surface *dst, size_t start, size_t end)
{
	t_rinfo	rinfo;

	rinfo.hfov2 = (float)game->setting->fov / 2;
	rinfo.vfov2 = (float)game->setting->vfov / 2;
	rinfo.step = (float)game->setting->fov / dst->w;
	rinfo.ren = ft_lstnew(NULL, sizeof(void*));
	rinfo.game = game;
	rinfo.start = start;
	rinfo.end = end;
	rinfo.dst = dst;
	get_hits(&rinfo, tanf(rinfo.vfov2 * PI_R));
	ft_lstrev(&rinfo.ren);
	render_hits(&rinfo, &(t_coord){
		wrap_float((0 * rinfo.step) + (rinfo.game->player->angle -
			rinfo.hfov2), 0, 360),
		wrap_float((rinfo.dst->w * rinfo.step) + (rinfo.game->player->angle -
			rinfo.hfov2), 0, 360)});
	return (NULL);
}

void		render(t_game *game, SDL_Surface *dst)
{
	t_ttask *tasks;
	t_ttask *new;
	t_point	bound;
	size_t	step;
	size_t	i;

	game->player->screen_updown = game->player->updown * dst->h;
	i = 0;
	step = dst->w / 7;
	bound = (t_point){0, step};
	while (i < 7)
	{
		if (i == 6)
			bound.y = dst->w;
		new = sdl_new_ttask(render_chunk, TFLAG_TASK_NO_DELETE,
			4, game, dst, (size_t)bound.x, (size_t)bound.y);
		sdl_add_tpool_ttask(game->pool, new);
		new->next = tasks;
		tasks = new;
		bound.x += step;
		bound.y += step;
		i++;
	}
	sdl_join_ttask_all(tasks);
	sdl_del_ttask_all(&tasks);
}
