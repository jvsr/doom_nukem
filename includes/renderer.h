/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 16:59:14 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/14 16:59:55 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "coord.h"
# include "campaign.h"
# include <SDL2/SDL_surface.h>
# include "rinfo.h"

# define HFOV_RANGE 180
# define VFOV_RANGE 180

# define CEILING_COLOR 0xFFFFFFF0
# define FLOOR_COLOR 0xFFF4EEB1

# define RENDER_THREADS 1

typedef struct s_list		t_list;
typedef struct s_game		t_game;
typedef struct s_player		t_player;
typedef enum e_texture		t_texture;
typedef void				(*t_objcreate)(t_coord *pos, t_sector *parent);

typedef struct	s_ybinfo
{
	int			h;
	SDL_Point	*ybounds;
	size_t		index;
	t_hinfo		*prev;
}				t_ybinfo;

void			render(t_game *game, SDL_Surface *dst);
t_hit			get_hit(t_coord *cosin,
					t_player *player, t_sector *sector, t_sector *prev);
void			draw_skybox(size_t x,
					SDL_Surface *dst, t_game *game, SDL_Point *bounds);
t_objrend		*new_rendobj(t_object *obj,
					t_sector *sec, float *flts, int x);
t_bool			sort_objs(const t_list *a, const t_list *b);
SDL_Point		set_ybounds(t_objrend *obj,
					t_game *game, t_ybinfo info);
t_list			**decals_on_vline(t_wall *wall, float perc_hit,
					float len, t_list **out);
SDL_Point		get_bounds(t_player *player,
					SDL_Surface *dst, t_hitem *hit, float tanvfov2);
void			get_hits(t_rinfo *rinfo, float tanvfov2);
void			render_hits(t_rinfo *rinfo, t_coord *range);
void			draw_vline(t_rinfo *rinfo,
					t_hitem *item, size_t index, SDL_Point *bounds);
void			render_objs(t_rinfo *rinfo, t_hinfo *info, t_coord *range);
void			draw_cline(SDL_Surface *dst,
					SDL_Point **bounds, size_t index, int colour);
void			draw_wall(t_rinfo *rinfo,
					SDL_Point **bounds, const size_t x, t_hit *hit);
void			draw_glass(t_rinfo *rinfo,
					SDL_Point **bounds, const size_t x, t_hit *hit);
void			draw_object(t_list *objs, t_rinfo *rinfo, t_hinfo *info);
void			delete_map(t_map **map);
void			draw_floor(t_rinfo *rin, t_hinfo *info);
void			draw_ceil(t_rinfo *rin, t_hinfo *info);
int				get_slope(t_hitem *item,
					t_wall *sw, float ang, t_rinfo *rin);
t_coord			get_vec_from_x(t_rinfo *rin, int x);
void			draw_sfloor(t_rinfo *rin, t_hinfo *info);
t_object		*new_chair(t_coord *pos, float offset, t_sector *parent);
t_object		*new_enemy(t_coord *pos, t_sector *parent);
t_object		*new_spike(t_coord *pos, t_sector *parent);
t_object		*new_key(t_coord *pos, t_sector *parent);
t_object		*new_health_pickup(t_coord *pos, t_sector *parent);
t_object		*new_start(t_coord *pos, t_sector *parent);
t_object		*new_end(t_coord *pos, t_sector *parent);
t_object		*new_ammo(t_coord *pos, t_sector *parent);
t_object		*new_slope(t_coord *pos, t_sector *parent);
t_object		*new_skybox_day(t_coord *pos, t_sector *parent);
t_object		*new_skybox_dusk(t_coord *pos, t_sector *parent);
t_object		*new_fminus(t_coord *pos, t_sector *parent);
t_object		*new_fplus(t_coord *pos, t_sector *parent);
t_object		*new_cplus(t_coord *pos, t_sector *parent);
t_object		*new_cminus(t_coord *pos, t_sector *parent);
void			free_sector(t_sector *sector);
void			free_obj(void *obj, size_t size);
void			free_wall(t_wall *wall);
t_bool			del_obj(t_object *obj, t_sector *sec);
t_hinfo			*new_hinfo(t_sector *sec, size_t ar_size, size_t start);
void			smash_glass(t_game *game, t_wall *glass, t_sector *sec);
void			render_fc(t_rinfo *rin, t_hinfo *info);

#endif
