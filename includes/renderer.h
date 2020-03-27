/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   renderer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/15 16:59:14 by ehollidg       #+#    #+#                */
/*   Updated: 2020/03/26 14:45:04 by euan          ########   odam.nl         */
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

typedef struct s_list		t_list;
typedef struct s_game		t_game;
typedef enum e_texture		t_texture;
typedef struct s_player		t_player;

typedef struct		s_ybinfo
{
	int		h;
	t_point	*ybounds;
	size_t	index;
	t_hinfo	*prev;
}					t_ybinfo;

void				render(t_game *game, SDL_Surface *dst);
SDL_Surface			*get_texture(t_game *game, t_texture texture);
void				load_textures(t_game *game);
t_hit				get_hit(t_coord *cosin,
						t_player *player, t_sector *sector, t_sector *prev);
void				draw_skybox(size_t x,
						SDL_Surface *dst, t_game *game, t_point *bounds);
t_objrend			*new_rendobj(t_object *obj,
						t_sector *sec, float *flts, int x);
t_bool				sort_objs(const t_list *a, const t_list *b);
float				get_object_angle_on_screen(t_object *object,
						t_player *player, t_coord *range);
t_point				set_ybounds(t_objrend *obj,
						t_game *game, t_ybinfo info);
void				get_s_object_index(t_game *game, void *anim);
SDL_Surface			*tex_from_anim(t_game *game, t_anim *anim);
void				get_r_object_index(t_game *game, void *anim);
t_list				**decals_on_vline(t_wall *wall, float perc_hit,
						float len, t_list **out);
void				get_enemy_index(t_game *game, void *anim);
t_point				get_bounds(t_player *player,
						SDL_Surface *dst, t_hitem *hit, float tanvfov2);
void				get_hits(t_rinfo *rinfo, float tanvfov2);
void				render_hits(t_rinfo *rinfo, t_coord *range);
void				draw_vline(t_rinfo *rinfo,
						t_hitem *item, size_t index, t_point *bounds);
void				render_objs(t_rinfo *rinfo, t_hinfo *info, t_coord *range);
void				draw_cline(SDL_Surface *dst,
						t_point **bounds, size_t index, int colour);
void				draw_wall(t_rinfo *rinfo,
						t_point **bounds, const size_t x, t_hit *hit);
void				draw_glass(t_rinfo *rinfo,
						t_point **bounds, const size_t x, t_hit *hit);
void				draw_object(t_list *objs, t_rinfo *rinfo, t_hinfo *info);
void				delete_map(t_map **map);
void				draw_floor(t_rinfo *rin, t_hinfo *info);
void				draw_ceil(t_rinfo *rin, t_hinfo *info);
int					get_slope(t_hitem *item,
						t_wall *sw, float ang, t_rinfo *rin);
t_coord				get_vec_from_x(t_rinfo *rin, int x);
void				draw_sfloor(t_rinfo *rin, t_hinfo *info);

#endif
