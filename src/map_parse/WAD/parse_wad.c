/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:05:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/24 21:52:46 by jvisser       ########   odam.nl         */
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
	ft_printf("Type:\t%d\nSize:\t%d\nDirP:\t%d\n\n",
		header->type,
		header->no_entries,
		header->loc_directory);
}

void	print_directory(t_wad_directory *directory)
{
	ft_printf("LumpP:\t%d\nSize:\t%d\nName:\t%s\n\n",
		directory->loc_lump,
		directory->size_lump,
		directory->name_lump);
}

static t_bool	is_wad_level(char *const name)
{
	size_t			i;
	size_t const	len = ft_strlen(name);

	if (0 >= len || name[0] != 'E')
		return (FALSE);
	i = 1;
	if (i >= len || ft_isdigit(name[i]) == FALSE)
		return (FALSE);
	while (i < len && ft_isdigit(name[i]) == TRUE)
		i++;
	if (i >= len || name[i] != 'M')
		return (FALSE);
	if (i + 1 > len || ft_isdigit(name[i + 1]) == FALSE)
		return (FALSE);
	return (TRUE);
}

static void	parse_wad_special(t_binary_read *wad_bin, t_wad *wad, t_wad_directory *directory, t_wad_state *state)
{
	// print_directory(directory);
	if (ft_strequ(directory->name_lump, "PLAYPAL"))
		parse_wad_playpal(wad_bin, wad->general, directory);
	else if (ft_strequ(directory->name_lump, "COLORMAP"))
		parse_wad_colormap(wad_bin, wad->general, directory);
	else if (ft_strequ(directory->name_lump, "ENDOOM"))
		parse_wad_endoom(wad_bin, wad->general, directory);
	else if (is_wad_level(directory->name_lump))
	{
		*state = wad_level;
		parse_wad_level(wad_bin, wad, directory);
	}
	else
		print_directory(directory);
}

static void	parse_wad_directory(t_binary_read *wad_bin, t_wad *wad, t_wad_directory *directory, t_wad_state *state)
{
	if (*state == wad_flat)
		parse_wad_flat(wad_bin, wad->general, directory);
	else if (*state == wad_sprite)
		parse_wad_sprite(wad_bin, wad->general, directory);
	else if (*state == wad_patch)
		parse_wad_patch(wad_bin, wad->general, directory);
	else
		parse_wad_special(wad_bin, wad, directory, state);
}

static void	loop_wad_directories(t_binary_read *wad_bin, t_wad *wad, t_wad_header *header)
{
	int				i;
	t_wad_state		state;
	t_wad_directory	*directory;

	i = 0;
	state = wad_none;
	while (i < header->no_entries)
	{
		wad_bin->content_pos = header->loc_directory + i * 16;
		directory = read_wad_directory(wad_bin);
		parse_wad_directory(wad_bin, wad, directory, &state);
		// print_directory(directory);
		free(directory->name_lump);
		free(directory);
		if (state == wad_level)
		{
			state = wad_none;
			i += 10;
		}
		i++;
	}
}

static t_wad	*alloc_wad(void)
{
	t_wad	*wad;

	wad = (t_wad*)ft_memalloc(sizeof(t_wad));
	if (wad == NULL)
		error_msg_errno("Failed to allocate wad");
	wad->general = (t_wad_general*)ft_memalloc(sizeof(t_wad_general));
	if (wad->general == NULL)
		error_msg_errno("Failed to allocate lumps");
	return (wad);
}

void	parse_wad(char *const filename)
{
	t_wad					*wad;
	t_wad_header			*header;
	t_binary_read *const	wad_bin = new_binary_read(filename, FALSE);

	wad = alloc_wad();
	wad_bin->endian = ENDIAN_LITTLE;
	header = read_wad_header(wad_bin);
	print_header(header);
	loop_wad_directories(wad_bin, wad, header);
	return ;
}
