/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:05:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/18 19:37:35 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "wad.h"
#include "serializer.h"
#include "error.h"
#include "types.h"

#include "libft/ft_printf.h"
static void	print_header(t_wad_header *header)
{
	ft_printf("Type:\t%d\nSize:\t%d\nDirP:\t%d\n",
		header->type,
		header->no_entries,
		header->loc_directory);
}

static void	loop_wad_directories(t_binary_read *wad, t_wad_header *header)
{
	int	i;

	i = 0;
	while (i < header->no_entries)
	{
		wad->content_pos = (header->no_entries + i) * 16;
		ft_printf("%d\n", wad->content_pos);
		i++;
	}
}

void	parse_wad(char *const filename)
{
	t_binary_read *const	wad = new_binary_read(filename, FALSE);
	t_wad_header			*header;

	wad->endian = ENDIAN_LITTLE;
	header = read_wad_header(wad);
	loop_wad_directories(wad, header);
	print_header(header);
	return ;
}
