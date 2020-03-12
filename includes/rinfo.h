/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rinfo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 16:15:51 by ehollidg       #+#    #+#                */
/*   Updated: 2020/03/10 15:09:37 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RINFO_H
# define RINFO_H

# include "coord.h"
# include "libft/ft_bool.h"
# include "types.h"
# include <SDL2/SDL_surface.h>

# define MAX_LIGHT_DIST 150.0
# define LEVEL_MULTIPLIER 4.0
# define MAX_OBJ_SECTORS 32
# define ANIMATIONS 4
# define MAX_ANIMATION_TIME 2000
# define OBJECT_COL_SIZE 1.0
# define MAX_HIT 2147483646

typedef struct s_sector	t_sector;
typedef struct s_game	t_game;
typedef struct s_list	t_list;
typedef struct s_player	t_player;
typedef struct s_object	t_object;
typedef struct s_hinfo	t_hinfo;

typedef struct	s_anim
{
	t_point		index;
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
}				t_wall;

struct			s_object
{
	t_coord	pos;
	t_coord	size;
	t_anim	img;
	void	*data;
	t_bool	is_enemy;
	float	col_radius;
	t_bool	can_col;
	void	(*on_collide)(t_game*, t_sector*, t_object*, t_player*);
};

typedef struct	s_enemy
{
	int				health;
	t_uint64		last_seen;
	t_enemystate	state;
	t_object		*obj;
	void			(*on_los)(t_game *, t_object *, t_player *);
	void			(*no_los)(t_game *);
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
	t_bool		has_sloop;
	float		angle;
	t_wall		*swall;
};

typedef struct	s_map
{
	t_sector	*sectors;
	t_uint64	sector_count;
	t_bool		has_skybox;
	t_texture	skybox;
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
	t_point		bounds;
}				t_secbounds;

typedef struct	s_zbuf
{
	float		dist;
	t_secbounds	bounds[MAX_OBJ_SECTORS];
}				t_zbuf;

typedef struct	s_hitem
{
	t_point		bounds;
	t_point		ybnds;
	t_hit		hit;
	t_coord		y;
	t_coord		st;
	int			hoffset;
	t_point		pre_bounds;
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
	t_point		floor_range;
	t_point		ceil_range;
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
	t_point		c_ybounds;
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
	t_point		ybounds;
	t_point		xbounds;
	t_point		c_xbounds;
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

#endif
