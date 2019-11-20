/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wad.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:05:57 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/20 21:39:31 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAD_H
# define WAD_H

typedef enum			e_wad_state
{
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
typedef struct			s_wad_lump
{
	char				*name;
	t_wad_thing			*things;
	struct s_wad_lump	*next;
}						t_wad_lump;

typedef struct			s_wad_general
{

}						t_wad_general;

typedef struct			s_wad
{
	char				*name;
	t_wad_lump			*lumps;
	t_wad_general		*general;
}						t_wad;


#endif
