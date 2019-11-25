/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wad.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:05:57 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/25 11:52:50 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAD_H
# define WAD_H

# include "SDL2/SDL_pixels.h"

# include "types.h"

typedef struct s_binary_read	t_binary_read;
typedef enum			e_wad_state
{
	wad_none,
	wad_level,
	wad_flat,
	wad_patch,
	wad_sprite,
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
	short				x_pos;
	short				y_pos;
	unsigned short		angle;
	unsigned short		types;
	unsigned short		spawn_flags;
}						t_wad_thing;
typedef struct			s_wad_linedef
{
	unsigned short		vertex_begin;
	unsigned short		vertex_end;
	unsigned short		flags;
	unsigned short		line_type;
	unsigned short		sector_tag;
	unsigned short		sidedef_right;
	unsigned short		sidedef_left;
}						t_wad_linedef;
typedef struct			s_wad_sidedef
{
	short				offset_x;
	short				offset_y;
	char				*texture_up;
	char				*texture_low;
	char				*texture_mid;
	unsigned short		sector;
}						t_wad_sidedef;
typedef struct			s_wad_vertex
{
	short				x;
	short				y;
}						t_wad_vertex;
typedef struct			s_wad_seg
{
	unsigned short		vertex_begin;
	unsigned short		vertex_end;
	short				angle;
	unsigned short		linedef_no;
	short				direction;
	short				offset;
}						t_wad_seg;
typedef struct			s_wad_ssector
{
	short				segment_no;
	short				segment_first;
}						t_wad_ssector;
typedef struct			s_wad_node
{
	short				partition_line_x;
	short				partition_line_y;
	short				change_partition_line_x;
	short				change_partition_line_y;
	long				right_box;
	long				left_box;
	short				right_child;
	short				left_child;
}						t_wad_node;
typedef struct			s_wad_sector
{
	short				height_floor;
	short				height_ceiling;
	char				*texture_floor;
	char				*texture_ceiling;
	short				light_level;
	unsigned short		sector_special;
	unsigned short		sector_tag;
}						t_wad_sector;
typedef struct			s_wad_blockmap
{
	unsigned short		grid_org_x;
	unsigned short		grid_org_y;
	short				colums_no;
	short				rows_no;
	short				*offsets;
	short				**blocklist;
}						t_wad_blockmap;
typedef struct			s_wad_level
{
	char				*name;
	size_t				things_amount;
	t_wad_thing			**things;
	size_t				linedefs_amount;
	t_wad_linedef		**linedefs;
	size_t				sidedefs_amount;
	t_wad_sidedef		**sidedefs;
	size_t				vertexes_amount;
	t_wad_vertex		**vertexes;
	size_t				segs_amount;
	t_wad_seg			**segs;
	size_t				ssectors_amount;
	t_wad_ssector		**ssectors;
	size_t				nodes_amount;
	t_wad_node			**nodes;
	size_t				sectors_amount;
	t_wad_sector		**sectors;
	unsigned char		**reject;
	t_wad_blockmap		*blockmap;
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
	t_wad_level			*levels;
	t_wad_general		*general;
}						t_wad;

void	print_directory(t_wad_directory *directory); //

void	parse_wad_level(t_binary_read *wad_bin, t_wad *wad, t_wad_directory *directory);

void	parse_wad_playpal(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory);
void	parse_wad_colormap(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory);
void	parse_wad_endoom(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory);
void	parse_wad_flat(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory);
void	parse_wad_patch(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory);
void	parse_wad_sprite(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory);

void	parse_wad_things(t_binary_read *wad_bin, t_wad_level *wad_level, t_wad_directory *directory);
void	parse_wad_linedefs(t_binary_read *wad_bin, t_wad_level *wad_level, t_wad_directory *directory);
void	parse_wad_sidedefs(t_binary_read *wad_bin, t_wad_level *wad_level, t_wad_directory *directory);
void	parse_wad_vertexes(t_binary_read *wad_bin, t_wad_level *wad_level, t_wad_directory *directory);
void	parse_wad_segs(t_binary_read *wad_bin, t_wad_level *wad_level, t_wad_directory *directory);
void	parse_wad_ssectors(t_binary_read *wad_bin, t_wad_level *wad_level, t_wad_directory *directory);
void	parse_wad_nodes(t_binary_read *wad_bin, t_wad_level *wad_level, t_wad_directory *directory);
void	parse_wad_sectors(t_binary_read *wad_bin, t_wad_level *wad_level, t_wad_directory *directory);
void	parse_wad_reject(t_binary_read *wad_bin, t_wad_level *wad_level, t_wad_directory *directory);
void	parse_wad_blockmap(t_binary_read *wad_bin, t_wad_level *wad_level, t_wad_directory *directory);

#endif
