/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rinfo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 16:15:51 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/10 14:29:03 by euan          ########   odam.nl         */
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

typedef struct s_sector	t_sector;
typedef struct s_game	t_game;
typedef struct s_list	t_list;

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
	t_sector	*window;
	t_anim		texture;
	t_coord		perc;
	t_list		*decals;
}				t_wall;

typedef struct	s_object
{
	t_coord		pos;
	t_coord		size;
	t_anim		img;
}				t_object;

struct			s_sector
{
	t_wall		*walls;
	t_object	*object;
	t_uint64	wall_count;
	t_uint64	object_count;
	float		floor;
	float		ceil;
	t_bool		has_ceiling;
	float		light_value;
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

#endif
