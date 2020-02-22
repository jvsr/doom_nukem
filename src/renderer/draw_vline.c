/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_vline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 15:35:04 by euan           #+#    #+#                */
/*   Updated: 2020/02/22 16:04:53 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_num.h"
#include "renderer.h"
#include "player.h"
#include "cmath.h"
#include "color.h"
#include "coord.h"
#include "rinfo.h"
#include "game.h"

static void draw_wall(SDL_Surface *dst, t_point *ybounds, size_t x, t_point *bounds, t_hit *hit, t_game *game)
{
	int *pixels;
	int i;
	t_point c_ybounds;
	t_bool check;
	t_list *decals;

	pixels = dst->pixels;
	decals = NULL;
	if (x >= (size_t)dst->w)
		return;
	*bounds = (t_point){ft_constrain(bounds->x, 0, dst->h), ft_constrain(bounds->y, 0, dst->h)};
	c_ybounds.x = ft_constrain(ybounds->x, bounds->x, bounds->y);
	c_ybounds.y = ft_constrain(ybounds->y, c_ybounds.x, bounds->y);
	i = c_ybounds.x;
	SDL_Surface *tex = tex_from_anim(game, &hit->wall->texture);
	int *t_pixels = tex->pixels;
	float len = get_distance(&hit->wall->corner_0, &hit->wall->corner_1);
	float perc = get_distance(&hit->pos, &hit->wall->corner_0) / len;
	float xperc = wrap_float(perc, 0, hit->wall->perc.x) / hit->wall->perc.x;
	int tex_x = xperc * tex->w;
	float intensity = ((MAX_LIGHT_DIST - clamp_float(hit->og_dist, 0, MAX_LIGHT_DIST)) / MAX_LIGHT_DIST) * hit->sect->light_value;
	check = TRUE;
	if (hit->wall->decals == NULL)
		check = FALSE;
	else if (*decals_on_vline(hit->wall, perc, len, &decals) == NULL)
		check = FALSE;
	if (!check)
		while (i < c_ybounds.y)
		{
			int y = (wrap_float((float)(i - ybounds->x) / (ybounds->y - ybounds->x), 0, hit->wall->perc.y) / hit->wall->perc.y) * tex->h;
			pixels[x + (dst->w * (dst->h - i - 1))] = rgba_intensity(t_pixels[(y * tex->w) + tex_x], intensity);
			i++;
		}
	else
	{
		float height = hit->sect->ceil - hit->sect->floor;
		while (i < c_ybounds.y)
		{
			float yperc = (float)(i - ybounds->x) / (ybounds->y - ybounds->x);
			int y = (wrap_float(yperc, 0, hit->wall->perc.y) / hit->wall->perc.y) * tex->h;
			int colour = t_pixels[(y * tex->w) + tex_x];
			t_list *tmp = decals;
			while (tmp)
			{
				t_decal *d_tmp = tmp->content;
				SDL_Surface *srf = tex_from_anim(game, &d_tmp->texture);
				float size = d_tmp->size.x / len;
				int x_tmp = (wrap_float(perc - d_tmp->pos.x, 0, size) / size) * srf->w;
				size = d_tmp->size.y / height;
				if (yperc >= d_tmp->pos.y && yperc <= d_tmp->pos.y + size)
				{
					y = (wrap_float(yperc - d_tmp->pos.y, 0, size) / size) * srf->h;
					colour = mix_color(colour, ((int*)srf->pixels)[x_tmp + (y * srf->w)]);
				}
				tmp = tmp->next;
			}
			pixels[x + (dst->w * (dst->h - i - 1))] = rgba_intensity(colour, intensity);
			i++;
		}
		ft_lstdel(&decals, NULL);
	}
}

static void draw_glass(SDL_Surface *dst, t_point *ybounds, size_t x, t_point *bounds, t_hit *hit, t_game *game)
{
	int *pixels;
	int i;
	t_point c_ybounds;
	t_bool check;
	t_list *decals;

	pixels = dst->pixels;
	decals = NULL;
	if (x >= (size_t)dst->w)
		return;
	*bounds = (t_point){ft_constrain(bounds->x, 0, dst->h), ft_constrain(bounds->y, 0, dst->h)};
	c_ybounds.x = ft_constrain(ybounds->x, bounds->x, bounds->y);
	c_ybounds.y = ft_constrain(ybounds->y, c_ybounds.x, bounds->y);
	i = c_ybounds.x;
	SDL_Surface *tex = tex_from_anim(game, &hit->wall->win_tex);
	int *t_pixels = tex->pixels;
	float len = get_distance(&hit->wall->corner_0, &hit->wall->corner_1);
	float perc = get_distance(&hit->pos, &hit->wall->corner_0) / len;
	float xperc = wrap_float(perc, 0, hit->wall->perc.x) / hit->wall->perc.x;
	int tex_x = xperc * tex->w;
	float intensity = ((MAX_LIGHT_DIST - clamp_float(hit->og_dist, 0, MAX_LIGHT_DIST)) / MAX_LIGHT_DIST) * hit->sect->light_value;
	check = TRUE;
	if (hit->wall->decals == NULL)
		check = FALSE;
	else if (*decals_on_vline(hit->wall, perc, len, &decals) == NULL)
		check = FALSE;
	if (!check)
		while (i < c_ybounds.y)
		{
			int y = (wrap_float((float)(i - ybounds->x) / (ybounds->y - ybounds->x), 0, hit->wall->perc.y) / hit->wall->perc.y) * tex->h;
			int val = x + (dst->w * (dst->h - i - 1));
			pixels[val] = mix_color(pixels[val], rgba_intensity(t_pixels[(y * tex->w) + tex_x], intensity));
			i++;
		}
	else
	{
		float height = hit->sect->ceil - hit->sect->floor;
		while (i < c_ybounds.y)
		{
			float yperc = (float)(i - ybounds->x) / (ybounds->y - ybounds->x);
			int y = (wrap_float(yperc, 0, hit->wall->perc.y) / hit->wall->perc.y) * tex->h;
			int colour = t_pixels[(y * tex->w) + tex_x];
			t_list *tmp = decals;
			while (tmp)
			{
				t_decal *d_tmp = tmp->content;
				SDL_Surface *srf = tex_from_anim(game, &d_tmp->texture);
				float size = d_tmp->size.x / len;
				int x_tmp = (wrap_float(perc - d_tmp->pos.x, 0, size) / size) * srf->w;
				size = d_tmp->size.y / height;
				if (yperc >= d_tmp->pos.y && yperc <= d_tmp->pos.y + size)
				{
					y = (wrap_float(yperc - d_tmp->pos.y, 0, size) / size) * srf->h;
					colour = mix_color(colour, ((int*)srf->pixels)[x_tmp + (y * srf->w)]);
				}
				tmp = tmp->next;
			}
			int val = x + (dst->w * (dst->h - i - 1));
			pixels[val] = mix_color(pixels[val], rgba_intensity(colour, intensity));
			i++;
		}
		ft_lstdel(&decals, NULL);
	}
}

static t_hinfo *find_hinfo(t_list *lst, t_sector *sec)
{
	t_hinfo *info;

	while (lst != NULL)
	{
		info = lst->content;
		if (sec == info->sec)
			return (info);
		lst = lst->next;
	}
	return (NULL);
}

void			draw_vline(t_rinfo *rinfo,
								t_hitem *item, size_t index, t_point *bounds)
{
	t_point	ybnds;
	t_point	nybnds;

	if (item == NULL || item->hit.sect == NULL)
		return ;
	ybnds.x = ((item->hit.sect->floor - item->y.x) / item->st.x) * (rinfo->dst->h) - rinfo->game->player->screen_updown;
	ybnds.y = rinfo->dst->h - (((item->y.y - item->hit.sect->ceil) / item->st.x) * (rinfo->dst->h)) - rinfo->game->player->screen_updown;
	if (ybnds.y < rinfo->dst->h && item->hit.sect->has_ceiling)
		draw_cline(rinfo->dst, (t_point*[2]){&(t_point){ybnds.y, rinfo->dst->h}, bounds}, index, CEILING_COLOR);
	else if (ybnds.y < rinfo->dst->h)
		draw_skybox(index, rinfo->dst, rinfo->game,
			(t_point[2]){(t_point){ybnds.y, rinfo->dst->h}, *bounds});
	if (ybnds.x > 0)
		draw_cline(rinfo->dst, (t_point*[2]){&(t_point){0, ybnds.x}, bounds}, index, FLOOR_COLOR);
	if (!item->hit.wall->is_portal && item->hit.sect->ceil > item->y.x &&
			item->hit.sect->floor < item->y.y)
		draw_wall(rinfo->dst, &ybnds, index, bounds, &item->hit, rinfo->game);
	else if (item->hit.sect->ceil > item->y.x &&
				item->hit.sect->floor < item->y.y)
	{
		nybnds = (find_hinfo(rinfo->ren, item->hit.sect))->hits[index].bounds;
		if (nybnds.x > 0)
			draw_wall(rinfo->dst, &(t_point){ybnds.x, nybnds.x}, index,
				bounds, &item->hit, rinfo->game);
		if (nybnds.y < rinfo->dst->h)
			draw_wall(rinfo->dst, &(t_point){nybnds.y, ybnds.y}, index,
				bounds, &item->hit, rinfo->game);
		if (item->hit.wall->is_window && nybnds.x < ybnds.x)
			draw_glass(rinfo->dst, &ybnds, index, bounds, &item->hit, rinfo->game);
		else if (item->hit.wall->is_window)
			draw_glass(rinfo->dst, &nybnds, index, bounds, &item->hit, rinfo->game);
	}
}