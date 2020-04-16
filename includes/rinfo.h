/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rinfo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 16:15:51 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/14 20:35:59 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RINFO_H
# define RINFO_H

# include "coord.h"
# include "libft/ft_bool.h"
# include "types.h"
# include <SDL2/SDL_surface.h>

# define MAX_LIGHT_DIST 300.0
# define LEVEL_MULTIPLIER 4.0
# define LEVEL_MULTIPLIER_P2 16.0
# define MAX_OBJ_SECTORS 32
# define ANIMATIONS 4
# define MAX_ANIMATION_TIME 2000
# define OBJECT_COL_SIZE 1.0
# define MAX_HIT 2147483646
# define CROSSHAIR_SIZE 0.005
# define CROSSHAIR_COLOUR 0xff000000

typedef struct s_sector	t_sector;
typedef struct s_game	t_game;
typedef struct s_list	t_list;
typedef struct s_player	t_player;
typedef struct s_object	t_object;
typedef struct s_hinfo	t_hinfo;

typedef void	(t_plyrcol)(t_game*, t_sector*, t_object*, t_player*);
typedef void	(t_onfunc)(t_game *, t_object *, t_player *);
typedef void	(t_nofunc)(t_game *, t_object *);

typedef struct	s_anim
{
	SDL_Point	index;
	t_texture	left[ANIMATIONS];
	t_texture	right[ANIMATIONS];
	t_texture	front[ANIMATIONS];
	t_texture	back[ANIMATIONS];
	t_texture	actions[ANIMATIONS];
	void		(*set_index)(t_game*, void*);
	void		*data;
	float		offset;
	float		angle;
}				t_anim;

typedef struct	s_decal
{
	t_coord		pos;
	t_coord		size;
	t_anim		texture;
}				t_decal;

typedef struct	s_wall
{
	t_coord		corner_0;
	t_coord		corner_1;
	t_bool		is_portal;
	t_bool		is_window;
	t_sector	*window;
	t_anim		texture;
	t_anim		win_tex;
	t_coord		perc;
	t_list		*decals;
	t_bool		is_door;
}				t_wall;

struct			s_object
{
	t_coord		pos;
	t_coord		size;
	t_anim		img;
	void		*data;
	t_bool		is_enemy;
	float		col_radius;
	t_bool		can_col;
	t_plyrcol	*on_collide;
	SDL_Point	ssize;
};

typedef struct	s_enemy
{
	int				health;
	t_uint64		last_seen;
	t_enemystate	state;
	t_object		*obj;
	t_onfunc		*on_los;
	t_nofunc		*no_los;
}				t_enemy;

struct			s_sector
{
	t_wall		*walls;
	t_list		*objects;
	t_uint64	wall_count;
	t_uint64	object_count;
	float		floor;
	float		ceil;
	t_texture	floor_tex;
	t_texture	ceil_tex;
	t_bool		has_ceiling;
	void		(*f_enter)(t_game *game, t_sector *cur_sector);
	void		(*f_exit)(t_game *game, t_sector *cur_sector);
	float		light_value;
	t_bool		has_slope;
	float		angle;
	t_wall		*swall;
};

typedef struct	s_map
{
	t_sector	*sectors;
	t_uint64	sector_count;
	t_bool		has_skybox;
	t_texture	skybox;
	t_bool		has_won;
}				t_map;

typedef struct	s_ritem
{
	t_sector	*sector;
	int			beginx;
	int			endx;
}				t_ritem;

typedef struct	s_hit
{
	float		dist;
	float		og_dist;
	t_coord		pos;
	t_wall		*wall;
	t_sector	*sect;
	float		angle;
}				t_hit;

typedef struct	s_objrend
{
	float		dist;
	t_object	*obj;
	t_sector	*sec;
	float		angle;
	int			x;
}				t_objrend;

typedef struct	s_secbounds
{
	t_sector	*sec;
	SDL_Point	bounds;
}				t_secbounds;

typedef struct	s_zbuf
{
	float		dist;
	t_secbounds	bounds[MAX_OBJ_SECTORS];
}				t_zbuf;

typedef struct	s_hitem
{
	SDL_Point	bounds;
	SDL_Point	ybnds;
	t_hit		hit;
	t_coord		y;
	t_coord		st;
	int			hoffset;
	SDL_Point	pre_bounds;
	float		tang;
}				t_hitem;

struct			s_hinfo
{
	t_sector	*sec;
	t_hitem		*hits;
	size_t		size;
	size_t		start;
	size_t		end;
	t_hinfo		*prev;
	SDL_Point	floor_range;
	SDL_Point	ceil_range;
};

typedef struct	s_rinfo
{
	t_game		*game;
	SDL_Surface	*dst;
	t_list		*ren;
	float		hfov2;
	float		vfov2;
	float		step;
	size_t		begin;
	size_t		start;
	size_t		end;
	int			*pixels;
}				t_rinfo;

typedef struct	s_winfo
{
	float		len;
	float		perc;
	float		intens;
	int			tex_x;
	int			*pixels;
	int			*t_pixels;
	SDL_Point	c_ybounds;
	size_t		x;
	SDL_Surface	*tex;
	t_list		*decals;
}				t_winfo;

typedef struct	s_oinfo
{
	t_object	*obj;
	t_list		**objs;
	t_hinfo		*info;
}				t_oinfo;

typedef struct	s_orend
{
	t_coord		y;
	t_coord		st;
	SDL_Point	ybounds;
	SDL_Point	xbounds;
	SDL_Point	c_xbounds;
	int			diff;
}				t_orend;

typedef struct	s_odraw
{
	t_game		*game;
	SDL_Surface	*dst;
	SDL_Surface	*tex;
	t_objrend	*obj;
	t_hinfo		*info;
	size_t		x;
	t_rinfo		*rinfo;
}				t_odraw;

typedef struct	s_rhits
{
	size_t		index;
	SDL_Point	*bounds;
}				t_rhits;

#endif
