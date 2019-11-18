/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   wad.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:05:57 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/18 14:46:54 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WAD_H
# define WAD_H

typedef enum	e_wad_type
{
	PWAD,
	IWAD,
}				t_wad_type;

typedef struct	s_wad_header
{
	t_wad_type				type;
	int						no_entries;
	int						loc_directory;
}				t_wad_header;

typedef struct	s_wad_directory
{
	int						loc_lump;
	int						size_lump;
	char *const				name_lump;
	struct s_wad_directory	*next;
}				t_wad_directory;

#endif
