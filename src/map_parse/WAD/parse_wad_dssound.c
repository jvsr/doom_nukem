/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_dssound.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 12:05:42 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/21 20:01:51 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "libft/ft_printf.h"

#include "wad.h"
#include "error.h"
#include "types.h"
#include "serializer.h"

static void	alloc_dssound(t_wad_general *wad_general)
{
	t_wad_dssound	*dssound;
	t_wad_dssound	*next;

	next = wad_general->dssound;
	dssound = (t_wad_dssound*)ft_memalloc(sizeof(t_wad_dssound));
	if (dssound == NULL)
		error_msg_errno("Failed to allocate dssound");
	dssound->next = next;
	wad_general->dssound = dssound;
}

static void	read_padding(t_binary_read *wad_bin)
{
	read_long(wad_bin);
	read_long(wad_bin);
}

static void	fill_wad_dssound(t_binary_read *wad_bin, t_wad_dssound *dssound)
{
	size_t	i;

	dssound->format = read_short(wad_bin);
	dssound->sample_rate = read_short(wad_bin);
	dssound->sample_count = read_int(wad_bin);
	dssound->samples = (t_uint8*)ft_memalloc(sizeof(t_uint8) * dssound->sample_count);
	if (dssound->samples == NULL)
		error_msg_errno("Failed to allocate dssound samples");
	ft_printf("format: %hu, sample_rate: %hu, sample_count %u\n", dssound->format, dssound->sample_rate, dssound->sample_count);
	i = 0;
	read_padding(wad_bin);
	while (i < dssound->sample_count)
	{
		dssound->samples[i] = read_char(wad_bin);
		ft_printf("sample: %hhu\n", dssound->samples[i]);
		i++;
	}
	read_padding(wad_bin);
}

void		parse_wad_dssound(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory)
{
	alloc_dssound(wad_general);
	wad_bin->content_pos = directory->loc_lump;
	ft_printf("DS-SOUND: %s\n", directory->name_lump);
	fill_wad_dssound(wad_bin, wad_general->dssound);
	ft_printf("\n");
}
