/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wad.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:05:57 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/22 15:07:00 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAD_H
# define WAD_H

# include "SDL2/SDL_pixels.h"

# include "types.h"

typedef struct s_binary_read	t_binary_read;
typedef enum			e_wad_state
{
	wad_pre,
	wad_first,
	wad_level,
	wad_sprite,
	wad_flat,
	wad_patch,
}						t_wad_state;

typedef enum			e_wad_type
{
	PWAD,
	IWAD,
}						t_wad_type;

typedef struct			s_wad_header
{
	t_wad_type				type;
	int						no_entries;
	int						loc_directory;
}						t_wad_header;

typedef struct			s_wad_directory
{
	int						loc_lump;
	int						size_lump;
	char					*name_lump;
}						t_wad_directory;

typedef struct			s_wad_thing
{
	struct s_wad_thing	*next;
}						t_wad_thing;
typedef struct			s_wad_level
{
	char				*name;
	t_wad_thing			*things;
	struct s_wad_level	*next;
}						t_wad_level;

typedef struct			s_wad_palette
{
	size_t				color_amount;
	SDL_Color			*color;
}						t_wad_playpal;
typedef struct			s_wad_colormap
{
	size_t				color_amount;
	t_uint8				*color;
}						t_wad_colormap;
typedef struct			s_wad_endoom
{
	t_uint8				*ascii;
	t_uint8				*color;
}						t_wad_endoom;
typedef struct			s_wad_general
{
	size_t				playpal_amount;
	t_wad_playpal		**playpal;
	size_t				colormap_amount;
	t_wad_colormap		**colormap;
	t_wad_endoom		*endoom;
}						t_wad_general;
typedef struct			s_wad
{
	char				*name;
	t_wad_level			*lumps;
	t_wad_general		*general;
}						t_wad;

void	parse_wad_playpal(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory);
void	parse_wad_colormap(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory);
void	parse_wad_endoom(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory);

#endif
