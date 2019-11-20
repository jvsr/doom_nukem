/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:05:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/20 21:47:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "wad.h"
#include "serializer.h"
#include "error.h"
#include "types.h"

#include "libft/ft_printf.h"
#include "libft/ft_str.h"
#include "libft/ft_mem.h"
#include "libft/ft_char.h"

static void	print_header(t_wad_header *header)
{
	ft_printf("Type:\t%d\nSize:\t%d\nDirP:\t%d\n",
		header->type,
		header->no_entries,
		header->loc_directory);
}

static void	print_directory(t_wad_directory *directory)
{
	ft_printf("LumpP:\t%d\nSize:\t%d\nName:\t%s\n",
		directory->loc_lump,
		directory->size_lump,
		directory->name_lump);
	// ft_putbytes(directory->name_lump, 8);
	ft_putchar('\n');
}

static void	parse_zero_directory(t_wad_directory *directory, t_wad *wad, t_wad_state state)
{
	if (ft_strmatch(directory->name_lump, "E*M*") == TRUE)
	{
		if (state == wad_level)
		{
			wad->lumps->next = (t_wad_lump*)malloc(sizeof(t_wad_lump));
			if (wad->lumps->next == NULL)
				error_msg_errno("Failed to allocate lumps");
			
		}
		wad->lumps->name = ft_strdup(directory->name_lump);
		// print_directory(directory);
	}
}

static void	parse_wad_directory(t_binary_read *wad_bin, t_wad *wad, t_wad_directory *directory, t_wad_state state)
{
	(void)wad_bin;
	if (directory->size_lump == 0)
		parse_zero_directory(directory, wad, state);
	// else if (ft_strequ(directory->name_lump, "THINGS"))
	// 	print_directory(directory);
}

static void	loop_wad_directories(t_binary_read *wad_bin, t_wad *wad, t_wad_header *header, t_wad_state state)
{
	int				i;
	t_wad_directory	*directory;

	wad->lumps = (t_wad_lump*)malloc(sizeof(t_wad_lump));
	if (wad->lumps == NULL)
		error_msg_errno("Failed to allocate lumps");
	wad->general = (t_wad_general*)malloc(sizeof(t_wad_general));
	if (wad->general == NULL)
		error_msg_errno("Failed to allocate lumps");

	i = 0;
	while (i < header->no_entries)
	{
		wad_bin->content_pos = header->loc_directory + i * 16;
		directory = read_wad_directory(wad_bin);
		parse_wad_directory(wad_bin, wad, directory, state);
		print_directory(directory);
		free(directory->name_lump);
		free(directory);
		i++;
	}
}

void	parse_wad(char *const filename)
{
	t_wad					*wad;
	t_wad_header			*header;
	t_wad_state				state;
	t_binary_read *const	wad_bin = new_binary_read(filename, FALSE);

	wad_bin->endian = ENDIAN_LITTLE;
	header = read_wad_header(wad_bin);
	wad = (t_wad*)malloc(sizeof(t_wad));
	if (wad == NULL)
		error_msg_errno("Failed to allocate wad");
	state = wad_first;
	loop_wad_directories(wad_bin, wad, header, state);
	print_header(header);
	return ;
}
