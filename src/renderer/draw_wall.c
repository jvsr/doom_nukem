/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_wall.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/22 16:13:23 by euan           #+#    #+#                */
/*   Updated: 2020/02/22 16:16:45 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"
#include "libft/ft_list.h"
#include "libft/ft_num.h"
#include "renderer.h"
#include "rinfo.h"
#include "coord.h"
#include "cmath.h"
#include "color.h"

void	draw_wall(t_rinfo *rinfo, t_point **bounds, size_t x, t_hit *hit)
{
	int *pixels;
	int i;
	t_point c_ybounds;
	t_bool check;
	t_list *decals;

	pixels = rinfo->dst->pixels;
	decals = NULL;
	if (x >= (size_t)rinfo->dst->w)
		return;
	*bounds[0] = (t_point){ft_constrain(bounds[0]->x, 0, rinfo->dst->h), ft_constrain(bounds[0]->y, 0, rinfo->dst->h)};
	c_ybounds.x = ft_constrain(bounds[1]->x, bounds[0]->x, bounds[0]->y);
	c_ybounds.y = ft_constrain(bounds[1]->y, c_ybounds.x, bounds[0]->y);
	i = c_ybounds.x;
	SDL_Surface *tex = tex_from_anim(rinfo->game, &hit->wall->texture);
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
			int y = (wrap_float((float)(i - bounds[1]->x) / (bounds[1]->y - bounds[1]->x), 0, hit->wall->perc.y) / hit->wall->perc.y) * tex->h;
			pixels[x + (rinfo->dst->w * (rinfo->dst->h - i - 1))] = rgba_intensity(t_pixels[(y * tex->w) + tex_x], intensity);
			i++;
		}
	else
	{
		float height = hit->sect->ceil - hit->sect->floor;
		while (i < c_ybounds.y)
		{
			float yperc = (float)(i - bounds[1]->x) / (bounds[1]->y - bounds[1]->x);
			int y = (wrap_float(yperc, 0, hit->wall->perc.y) / hit->wall->perc.y) * tex->h;
			int colour = t_pixels[(y * tex->w) + tex_x];
			t_list *tmp = decals;
			while (tmp)
			{
				t_decal *d_tmp = tmp->content;
				SDL_Surface *srf = tex_from_anim(rinfo->game, &d_tmp->texture);
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
			pixels[x + (rinfo->dst->w * (rinfo->dst->h - i - 1))] = rgba_intensity(colour, intensity);
			i++;
		}
		ft_lstdel(&decals, NULL);
	}
}
