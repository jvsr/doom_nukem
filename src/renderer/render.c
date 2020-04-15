/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 12:39:17 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 11:08:11 by euan          ########   odam.nl         */
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
	rinfo.pixels = dst->pixels;
	get_hits(&rinfo, tanf(rinfo.vfov2 * PI_R));
	ft_lstrev(&rinfo.ren);
	render_hits(&rinfo, &(t_coord){
		wrap_float((0 * rinfo.step) + (rinfo.game->player->angle -
			rinfo.hfov2), 0, 360),
		wrap_float((rinfo.dst->w * rinfo.step) + (rinfo.game->player->angle -
			rinfo.hfov2), 0, 360)});
	return (NULL);
}

static void	render_crosshair(SDL_Surface *dst)
{
	const int		csize = dst->w * CROSSHAIR_SIZE;
	size_t			x;
	size_t			y;
	SDL_Point		i;
	int				*pixels;

	x = (dst->w / 2) - (csize * 0.5);
	i.x = 0;
	pixels = dst->pixels;
	while (i.x < csize)
	{
		y = (dst->h / 2) - (csize * 0.5);
		i.y = 0;
		while (i.y < csize)
		{
			pixels[x + (y * dst->w)] = CROSSHAIR_COLOUR;
			y++;
			i.y++;
		}
		x++;
		i.x++;
	}
}

static void	bound_task(SDL_Point *bound,
								t_game *game, t_ttask *new, size_t step)
{
	sdl_add_tpool_ttask(game->pool, new);
	*bound = (SDL_Point){bound->x + step, bound->y + step};
}

void		render(t_game *game, SDL_Surface *dst)
{
	t_ttask		*tasks;
	t_ttask		*new;
	SDL_Point	bound;
	size_t		step;
	size_t		i;

	game->player->screen_updown = game->player->updown * dst->h;
	i = 0;
	tasks = NULL;
	step = dst->w / RENDER_THREADS;
	bound = (SDL_Point){0, step};
	while (i < RENDER_THREADS)
	{
		if (i == (RENDER_THREADS - 1))
			bound.y = dst->w;
		new = sdl_new_ttask(render_chunk, TFLAG_TASK_NO_DELETE,
			4, game, dst, (size_t)bound.x, (size_t)bound.y);
		bound_task(&bound, game, new, step);
		new->next = tasks;
		tasks = new;
		i++;
	}
	sdl_join_ttask_all(tasks);
	sdl_del_ttask_all(&tasks);
	render_crosshair(dst);
}
