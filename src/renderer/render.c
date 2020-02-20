/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   render.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 12:39:17 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/19 12:39:17 by ehollidg      ########   odam.nl         */
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

static t_hinfo	*new_hinfo(t_sector *sec, size_t ar_size, size_t start)
{
	t_hinfo *info;

	info = ft_memalloc(sizeof(t_hinfo));
	if (info == NULL)
		error_msg_errno("Error allocating hinfo");
	info->sec = sec;
	info->hits = (t_hitem*)ft_memalloc(sizeof(t_hitem) * ar_size);
	if (info->hits == NULL)
		error_msg_errno("Error allocating hinfo hits");
	info->size = ar_size;
	info->start = start;
	return (info);
}

static void		del_hinfo(void *info, size_t size)
{
	t_hinfo *h;

	(void)size;
	h = info;
	ft_memdel((void**)&h->hits);
	ft_memdel((void**)&h);
}

static t_point	get_bounds(t_player *player, SDL_Surface *dst, t_hitem *hit, float vfov2)
{
	t_point	new;

	hit->st.y = hit->hit.dist * tanf(vfov2 * PI_R);
	hit->y.x = player->height + player->heightoffset;
	hit->y.y = hit->y.x + hit->st.y;
	hit->y.x -= hit->st.y;
	hit->st.x = hit->st.y * 2;
	new = (t_point){0, 0};
	if (!hit->hit.wall->is_portal && hit->hit.sect->ceil > hit->y.x && hit->hit.sect->floor < hit->y.y)
	{
		new.x = (((hit->hit.sect->floor - hit->y.x) / hit->st.x) *
				dst->h) - player->screen_updown;
		new.y = dst->h - (((hit->y.y - hit->hit.sect->ceil) / hit->st.x) *
				dst->h) - player->screen_updown;
	}
	else if (hit->hit.sect->ceil > hit->y.x && hit->hit.sect->floor < hit->y.y)
	{
		new.x = (((hit->hit.wall->window->floor - hit->y.x) / hit->st.x) *
				dst->h) - player->screen_updown;
		new.y = dst->h - (((hit->y.y - hit->hit.wall->window->ceil) / hit->st.x) *
				dst->h) - player->screen_updown;
	}
	return (new);
}

static void	move_sector(t_hit *hit, t_list *ren, t_hinfo **prev, t_hinfo **info, size_t index)
{
	t_list	*tmp;
	t_hinfo	*htmp;

	*prev = *info;
	tmp = ren;
	while (tmp)
	{
		htmp = tmp->content;
		if (hit->wall->window == htmp->sec)
		{
			*info = htmp;
			return ;
		}
		tmp = tmp->next;
	}
	ft_lstaddbck(&ren, ft_lstnew(
		new_hinfo(hit->wall->window, (*info)->size, index), sizeof(t_hinfo)));
	*info = ft_lstlast(ren)->content;
}

static void hit(t_game *game, SDL_Surface *dst, size_t index, t_list *ren, float hfov2, t_coord *cosin, float angle, float vfov2)
{
	t_hinfo *info;
	t_hitem	*hit;
	t_hinfo	*prev;
	t_point	tmp;

	info = ren->content;
	prev = info;
	tmp = (t_point){0, dst->h};
	hit = NULL;
	while (tmp.x != tmp.y && (hit == NULL || hit->hit.wall->is_portal))
	{
		info->prev = prev;
		info->end = index;
		hit = info->hits + index;
		hit->hit = get_hit(cosin, game->player, info->sec, prev->sec);
		if (angle > hfov2)
			hit->hit.dist *= cosf((angle - hfov2) * PI_R);
		else if (angle < hfov2)
			hit->hit.dist *= cosf((hfov2 - angle) * PI_R);
		hit->hit.og_dist = hit->hit.dist;
		hit->hit.dist *= LEVEL_MULTIPLIER;
		tmp = get_bounds(game->player, dst, hit, vfov2);
		hit->bounds = tmp;
		if (tmp.x != tmp.y && hit->hit.wall->is_portal == TRUE)
			move_sector(&hit->hit, ren, &prev, &info, index);
	}
}

static void	get_hits(t_game *game, SDL_Surface *dst, size_t start, size_t end, t_list *ren, float hfov2, float step, float vfov2)
{
	float	angle;
	float	r_angle;
	t_coord	cosin;

	ren->content = new_hinfo(game->map->sectors + game->player->cur_sector,
						end - start, start);
	while (start < end)
	{
		angle = step * start;
		r_angle = wrap_float(angle + (game->player->angle - hfov2), 0, 360)
					* PI_R;
		cosin = (t_coord){cosf(r_angle), sinf(r_angle)};
		hit(game, dst, start, ren, hfov2, &cosin, angle, vfov2);
		start++;
	}
}

static void draw_cline(SDL_Surface *dst, t_point *ybounds, size_t index, int colour, t_point *bounds)
{
	int *pixels;
	int i;
	t_point c_ybounds;

	pixels = dst->pixels;
	if (index >= (size_t)dst->w)
		return;
	*bounds = (t_point){ft_constrain(bounds->x, 0, dst->h), ft_constrain(bounds->y, 0, dst->h)};
	c_ybounds.x = ft_constrain(ybounds->x, bounds->x, bounds->y);
	c_ybounds.y = ft_constrain(ybounds->y, c_ybounds.x, bounds->y);
	i = c_ybounds.x;
	if (colour != -1)
	{
		while (i < c_ybounds.y)
		{
			pixels[index + (dst->w * (dst->h - i - 1))] = colour;
			i++;
		}
	}
}

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

static void	draw_vline(t_game *game, SDL_Surface *dst, t_hitem *item, size_t index, t_list *ren, t_point *bounds)
{
	t_point	ybnds;
	t_point	nybnds;

	if (item == NULL || item->hit.sect == NULL)
		return ;
	ybnds.x = (((item->hit.sect->floor - item->y.x) / item->st.x) * (dst->h))
					- game->player->screen_updown;
	ybnds.y = dst->h - (((item->y.y - item->hit.sect->ceil) / item->st.x)
					* (dst->h)) - game->player->screen_updown;
	if (ybnds.y < dst->h && item->hit.sect->has_ceiling)
		draw_cline(dst, &(t_point){ybnds.y, dst->h}, index, CEILING_COLOR,
			bounds);
	else if (ybnds.y < dst->h)
		draw_skybox(index, dst, game,
			(t_point[2]){(t_point){ybnds.y, dst->h}, *bounds});
	if (ybnds.x > 0)
		draw_cline(dst, &(t_point){0, ybnds.x}, index, FLOOR_COLOR,
			bounds);
	if (!item->hit.wall->is_portal && item->hit.sect->ceil > item->y.x &&
			item->hit.sect->floor < item->y.y)
		draw_wall(dst, &ybnds, index, bounds, &item->hit, game);
	else if (item->hit.sect->ceil > item->y.x &&
				item->hit.sect->floor < item->y.y)
	{
		nybnds = (find_hinfo(ren, item->hit.sect))->hits[index].bounds;
		if (nybnds.x > 0)
			draw_wall(dst, &(t_point){ybnds.x, nybnds.x}, index,
				bounds, &item->hit, game);
		if (nybnds.y < dst->h)
			draw_wall(dst, &(t_point){nybnds.y, ybnds.y}, index,
				bounds, &item->hit, game);
	}
}

static void	check_obj(t_object *obj, t_game *game, SDL_Surface *dst, float objang, t_list **objs, t_coord *range, float hfov2, t_hinfo *info)
{
	float	tmpang;
	int		scrnspc;
	float	dist;

	obj->img.angle = objang;
	tmpang = calc_fov(range->x, objang);
	scrnspc = (int)((tmpang / calc_fov(range->x, range->y)) * dst->w);
	dist = get_distance(&game->player->pos, &obj->pos);
	if (tmpang > hfov2)
		dist *= cosf((tmpang - hfov2) * PI_R);
	else if (tmpang < hfov2)
		dist *= cosf((hfov2 - tmpang) * PI_R);
	if (dist < info->hits[scrnspc].hit.og_dist)
		ft_lstaddbck(objs, ft_lstnew(new_rendobj(obj, info->sec,
			(float[2]){dist, objang}, scrnspc), sizeof(t_objrend)));
}

static void draw_object(t_list *objs, SDL_Surface *dst, t_game *game, t_hinfo *info)
{
	int *pixels;
	int count;

	pixels = dst->pixels;
	count = 0;
	while (objs)
	{
		float y1, y0, t0, s;
		t_point ybounds;
		t_point c_ybounds;
		t_point xbounds;
		t_point c_xbounds;
		t_objrend *obj = objs->content;
		int x;

		t0 = obj->dist;
		y0 = game->player->height + game->player->heightoffset;
		y1 = y0 + t0;
		y0 -= t0;
		s = t0 * 2;
		ybounds = (t_point){(((obj->sec->floor - y0) / s)* (dst->h)) - game->player->screen_updown,
			dst->h - (((y1 - (obj->obj->size.y + obj->sec->floor)) / s) * (dst->h)) - game->player->screen_updown};
		int diff = (abs(ybounds.y - ybounds.x) * (obj->obj->size.x / obj->obj->size.y)) / 2;
		xbounds = (t_point){obj->x - diff, obj->x + diff};
		c_xbounds.x = ft_constrain(xbounds.x, 0, dst->w - 1);
		c_xbounds.y = ft_constrain(xbounds.y, c_xbounds.x, dst->w - 1);
		x = c_xbounds.x;
		SDL_Surface *tex = tex_from_anim(game, &obj->obj->img);
		while (x < c_xbounds.y)
		{
			if (x >= 0 && x < dst->w && obj->dist < info->hits[x].hit.dist)
			{
				c_ybounds = set_ybounds(obj, game, (t_ybinfo){dst->h, &ybounds, x, info->prev});
				int *t_pixels = tex->pixels;
				float perc = (float)(x - xbounds.x) / (xbounds.y - xbounds.x);
				int tex_x = perc * (tex->w - 1);
				float intensity = ((MAX_LIGHT_DIST - clamp_float(obj->dist, 0, MAX_LIGHT_DIST)) / MAX_LIGHT_DIST) * obj->sec->light_value;
				int i = c_ybounds.x;
				while (i < c_ybounds.y)
				{
					int y = (float)(i - ybounds.x) / (ybounds.y - ybounds.x) * tex->h;
					int im_pixel = t_pixels[((tex->h - y - 1) * tex->w) + tex_x];
					int in_pix = x + (dst->w * (dst->h - i - 1));
					if (im_pixel != 0)
						pixels[in_pix] = mix_color(pixels[in_pix], rgba_intensity(im_pixel , intensity));
					i++;
				}
			}
			x++;
		}
		objs = objs->next;
		count++;
	}
}

static void render_objs(t_game *game, SDL_Surface *dst, t_hinfo *info, t_coord *range, float hfov2)
{
	t_list		*objs;
	size_t		i;
	float		objang;
	t_object	*obj;

	objs = NULL;
	i = 0;
	while (i < info->sec->object_count)
	{
		obj = ft_lstindex(info->sec->objects, i)->content;
		objang = get_object_angle_on_screen(obj, game->player, range);
		if (objang >= 0)
			check_obj(obj, game, dst, objang, &objs, range, hfov2, info);
		i++;
	}
	draw_object(objs, dst, game, info);
	ft_lstdel(&objs, NULL);
}

static void	render_hits(t_game *game, SDL_Surface *dst, t_list *ren, float hfov2, t_coord *range)
{
	t_list	*lst;
	t_hinfo	*info;
	size_t	index;
	size_t	l_index;
	t_point	bounds;

	l_index = ft_lstlen(ren);
	info = NULL;
	while (l_index > 0)
	{
		lst = ft_lstindex(ren, l_index - 1);
		info = lst->content;
		lst = ft_lstindex(ren, l_index - 2);
		index = info->start;
		while (index < info->end)
		{
			if (l_index == 1)
				bounds = (t_point){0, dst->h};
			else
				bounds = info->prev->hits[index].bounds;
			draw_vline(game, dst, info->hits + index, index, ren, &bounds);
			index++;
		}
		render_objs(game, dst, info, range, hfov2);
		l_index--;
	}
	ft_lstdel(&ren, del_hinfo);
}

static void render_chunk(t_game *game, SDL_Surface *dst, size_t start, size_t end)
{
	float	hfov2;
	float	step;
	float	vfov2;
	t_list	*ren;

	hfov2 = (float)game->setting->fov * 0.5;
	vfov2 = (float)game->setting->vfov * 0.5;
	step = (float) game->setting->fov / dst->w;
	ren = ft_lstnew(NULL, sizeof(void*));
	get_hits(game, dst, start, end, ren, hfov2, step, vfov2);
	render_hits(game, dst, ren, hfov2, &(t_coord){
		wrap_float((start * step) + (game->player->angle - hfov2), 0, 360),
		wrap_float((end * step) + (game->player->angle - hfov2), 0, 360)});
}

void	render(t_game *game, SDL_Surface *dst)
{
	game->player->screen_updown = game->player->updown * dst->h;
	render_chunk(game, dst, 0, dst->w - 1);
}
