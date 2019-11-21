/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_endoom.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 12:05:42 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/21 20:33:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "wad.h"
#include "error.h"
#include "serializer.h"

#include "libft/ft_printf.h" //
#include "libft/ft_char.h" //
static void				print_endoom(t_wad_endoom *endoom)
{
	size_t	i;

	i = 0;
	while (i < 2000)
	{
		ft_printf("%c", endoom->ascii[i]);
		if (i % 25 == 24)
			ft_putchar('\n');
		i++;
	}
}

static void				alloc_endoom(t_wad_general *wad_general)
{
	wad_general->endoom = (t_wad_endoom*)ft_memalloc(sizeof(t_wad_endoom));
	if (wad_general->endoom == NULL)
		error_msg_errno("Failed to allocate endoom");
}

static void				alloc_color(t_wad_endoom *endoom, size_t color_amount)
{
	endoom->ascii = (uint8_t*)ft_memalloc(sizeof(uint8_t) * color_amount);
	if (endoom->ascii == NULL)
			error_msg_errno("Failed to allocate endoom ascii");
	endoom->color = (uint8_t*)ft_memalloc(sizeof(uint8_t) * color_amount);
	if (endoom->color == NULL)
			error_msg_errno("Failed to allocate endoom colors");
}

static void				fill_wad_endoom(t_binary_read *wad_bin, t_wad_endoom *endoom)
{
	size_t			i;
	size_t const	size = 2000;

	alloc_color(endoom, size);
	i = 0;
	while (i < size)
	{
		endoom->ascii[i] = read_char(wad_bin);
		endoom->color[i] = read_char(wad_bin);
		i++;
	}
}

void	parse_wad_endoom(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory)
{
	if (directory->size_lump == 4000)
		alloc_endoom(wad_general);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid ENDOOM lump");
	wad_bin->content_pos = directory->loc_lump;
	fill_wad_endoom(wad_bin, wad_general->endoom);
	print_endoom(wad_general->endoom);
}
