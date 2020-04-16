/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_wall.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 16:13:23 by euan          #+#    #+#                 */
/*   Updated: 2020/04/06 11:08:57 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "libft/ft_num.h"
#include "textures.h"
#include "renderer.h"
#include "rinfo.h"
#include "coord.h"
#include "cmath.h"
#include "color.h"

static void	render_decal_list(const t_rinfo *rinfo,
								const t_winfo *win, int *ivals, float *fvals)
{
	t_list		*tmp;
	t_decal		*d_tmp;
	SDL_Surface	*srf;

	tmp = win->decals;
	while (tmp)
	{
		d_tmp = tmp->content;
		srf = sdl_from_anim(rinfo->game, &d_tmp->texture);
		fvals[1] = d_tmp->size.x / win->len;
		ivals[3] = (wrap_float(win->perc - d_tmp->pos.x, 0, fvals[1]) /
					fvals[1]) * srf->w;
		fvals[1] = d_tmp->size.y / fvals[0];
		if (fvals[2] >= d_tmp->pos.y && fvals[2] <= d_tmp->pos.y + fvals[1])
		{
			ivals[1] = (wrap_float(fvals[2] - d_tmp->pos.y, 0, fvals[1]) /
						fvals[1]) * srf->h;
			ivals[2] = mix_color(ivals[2], ((int*)srf->pixels)[ivals[3] +
						(ivals[1] * srf->w)]);
		}
		tmp = tmp->next;
	}
}

static void	render_decals(SDL_Point *const *bounds,
						const t_rinfo *rinfo, const t_hit *hit, t_winfo *win)
{
	float		fvals[3];
	int			ivals[4];
	const int	tex_x = win->tex_x;
	const float	perc_y = hit->wall->perc.y;
	const int	*t_pixels = win->t_pixels;

	fvals[0] = hit->sect->ceil - hit->sect->floor;
	ivals[0] = win->c_ybounds.x;
	while (ivals[0] < win->c_ybounds.y)
	{
		fvals[2] = (float)(ivals[0] - bounds[1]->x) /
				(bounds[1]->y - bounds[1]->x);
		ivals[1] = (wrap_float(fvals[2], 0, perc_y) / perc_y) * win->tex->h;
		ivals[2] = t_pixels[(ivals[1] * win->tex->w) + tex_x];
		render_decal_list(rinfo, win, ivals, fvals);
		win->pixels[win->x + (rinfo->dst->w * (rinfo->dst->h - ivals[0] - 1))] =
				rgba_set_intensity(ivals[2], win->intens);
		ivals[0]++;
	}
}

static void	render_wall(SDL_Point *const *bounds, const t_rinfo *rinfo,
												const double hity, t_winfo *win)
{
	const int			tex_x = win->tex_x;
	const SDL_Surface	*tex = win->tex;
	const int			*t_pixels = win->t_pixels;
	int					i;
	int					y;

	i = win->c_ybounds.x;
	while (i < win->c_ybounds.y)
	{
		y = (wrap_float((float)(i - bounds[1]->x) / (bounds[1]->y -
			bounds[1]->x), 0, hity) / hity) * tex->h;
		win->pixels[win->x + (rinfo->dst->w * (rinfo->dst->h - i - 1))] =
			rgba_set_intensity(t_pixels[(y * tex->w) + tex_x], win->intens);
		i++;
	}
}

void		draw_wall(t_rinfo *rinfo,
							SDL_Point **bounds, const size_t x, t_hit *hit)
{
	t_winfo		win;

	ft_bzero(&win, sizeof(t_winfo));
	win.pixels = rinfo->dst->pixels;
	win.x = x;
	if (x >= (size_t)rinfo->dst->w)
		return ;
	*bounds[0] = (SDL_Point){ft_constrain(bounds[0]->x, 0, rinfo->dst->h),
					ft_constrain(bounds[0]->y, 0, rinfo->dst->h)};
	win.c_ybounds.x = ft_constrain(bounds[1]->x, bounds[0]->x, bounds[0]->y);
	win.c_ybounds.y = ft_min(bounds[1]->y, bounds[0]->y);
	win.tex = sdl_from_anim(rinfo->game, &hit->wall->texture);
	win.t_pixels = win.tex->pixels;
	win.len = get_distance(&hit->wall->corner_0, &hit->wall->corner_1);
	win.perc = get_distance(&hit->pos, &hit->wall->corner_0) / win.len;
	win.tex_x = (wrap_float(win.perc, 0, hit->wall->perc.x) / hit->wall->perc.x)
					* win.tex->w;
	win.intens = ((MAX_LIGHT_DIST - clamp_float(hit->og_dist, 0,
					MAX_LIGHT_DIST)) / MAX_LIGHT_DIST) * hit->sect->light_value;
	if (hit->wall->decals == NULL)
		return (render_wall(bounds, rinfo, hit->wall->perc.y, &win));
	if (*decals_on_vline(hit->wall, win.perc, win.len, &win.decals) == NULL)
		return (render_wall(bounds, rinfo, hit->wall->perc.y, &win));
	render_decals(bounds, rinfo, hit, &win);
	ft_lstdel(&win.decals, NULL);
}
