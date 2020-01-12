/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rinfo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/07 16:15:51 by ehollidg       #+#    #+#                */
/*   Updated: 2020/01/07 16:15:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RINFO_H
# define RINFO_H

# include "coord.h"
# include "libft/ft_bool.h"
# include "types.h"
# include <SDL2/SDL_surface.h>

# define MAX_RENDERS 32
# define MAX_LIGHT_DIST 200.0

typedef struct s_sector	t_sector;

typedef struct	s_wall
{
	t_coord		corner_0;
	t_coord		corner_1;
	t_bool		is_portal;
	t_sector	*window;
}				t_wall;

struct			s_sector
{
	t_wall		*walls;
	t_uint64	wall_count;
	float		floor;
	float		ceil;
};

typedef struct	s_map
{
	t_sector	*sectors;
	t_uint64	sector_count;
}				t_map;

typedef struct	s_iminfo
{
	SDL_Surface	*image;
	int			pos;
	int			begin;
	int			end;
}				t_iminfo;

typedef struct	s_drawinfo
{
	int			x;
	int			y0;
	int			y1;
	int			top;
	int			middle;
	int			bottom;
	t_iminfo	draw;
}				t_drawinfo;

typedef struct	s_ritem
{
	t_sector	*sector;
	int			beginx;
	int			endx;
}				t_ritem;


#endif
