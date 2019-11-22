/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_endoom.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 12:05:42 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/22 15:21:27 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>

#include "libft/ft_mem.h"

#include "wad.h"
#include "error.h"
#include "table.h"
#include "serializer.h"

#include "libft/ft_term.h" //
#include "libft/ft_printf.h" //
#include "libft/ft_char.h" //

#define	ANSI_SIZE (80 * 25)

static t_tablepair_int const g_eascii_unicode[] = {
	{"\u00C7", 128},
	{"\u00FC", 129},
	{"\u00E9", 130},
	{"\u00E2", 131},
	{"\u00E4", 132},
	{"\u00E0", 133},
	{"\u00E5", 134},
	{"\u00E7", 135},
	{"\u00EA", 136},
	{"\u00EB", 137},
	{"\u00E8", 138},
	{"\u00EF", 139},
	{"\u00EE", 140},
	{"\u00EC", 141},
	{"\u00C4", 142},
	{"\u00C5", 143},
	{"\u00C9", 144},
	{"\u00E6", 145},
	{"\u00C6", 146},
	{"\u00F4", 147},
	{"\u00F6", 148},
	{"\u00F2", 149},
	{"\u00FB", 150},
	{"\u00F9", 151},
	{"\u00FF", 152},
	{"\u00D6", 153},
	{"\u00DC", 154},
	{"\u00A2", 155},
	{"\u00A3", 156},
	{"\u00A5", 157},
	{"\u20A7", 158},
	{"\u0192", 159},
	{"\u00E1", 160},
	{"\u00ED", 161},
	{"\u00F3", 162},
	{"\u00FA", 163},
	{"\u00F1", 164},
	{"\u00D1", 165},
	{"\u00AA", 166},
	{"\u00BA", 167},
	{"\u00BF", 168},
	{"\u2310", 169},
	{"\u00AC", 170},
	{"\u00BD", 171},
	{"\u00BC", 172},
	{"\u00A1", 173},
	{"\u00AB", 174},
	{"\u00BB", 175},
	{"\u2591", 176},
	{"\u2592", 177},
	{"\u2593", 178},
	{"\u2502", 179},
	{"\u2524", 180},
	{"\u2561", 181},
	{"\u2562", 182},
	{"\u2556", 183},
	{"\u2555", 184},
	{"\u2563", 185},
	{"\u2551", 186},
	{"\u2557", 187},
	{"\u255D", 188},
	{"\u255C", 189},
	{"\u255B", 190},
	{"\u2510", 191},
	{"\u2514", 192},
	{"\u2534", 193},
	{"\u252C", 194},
	{"\u251C", 195},
	{"\u2500", 196},
	{"\u253C", 197},
	{"\u255E", 198},
	{"\u255F", 199},
	{"\u255A", 200},
	{"\u2554", 201},
	{"\u2569", 202},
	{"\u2566", 203},
	{"\u2560", 204},
	{"\u2550", 205},
	{"\u256C", 206},
	{"\u2567", 207},
	{"\u2568", 208},
	{"\u2564", 209},
	{"\u2565", 210},
	{"\u2559", 211},
	{"\u2558", 212},
	{"\u2552", 213},
	{"\u2553", 214},
	{"\u256B", 215},
	{"\u256A", 216},
	{"\u2518", 217},
	{"\u250C", 218},
	{"\u2588", 219},
	{"\u2584", 220},
	{"\u258C", 221},
	{"\u2590", 222},
	{"\u2580", 223},
	{"\u03B1", 224},
	{"\u00DF", 225},
	{"\u0393", 226},
	{"\u03C0", 227},
	{"\u03A3", 228},
	{"\u03C3", 229},
	{"\u00B5", 230},
	{"\u03C4", 231},
	{"\u03A6", 232},
	{"\u0398", 233},
	{"\u03A9", 234},
	{"\u03B4", 235},
	{"\u221E", 236},
	{"\u03C6", 237},
	{"\u03B5", 238},
	{"\u2229", 239},
	{"\u2261", 240},
	{"\u00B1", 241},
	{"\u2265", 242},
	{"\u2264", 243},
	{"\u2320", 244},
	{"\u2321", 245},
	{"\u00F7", 246},
	{"\u2248", 247},
	{"\u00B0", 248},
	{"\u2219", 249},
	{"\u00B7", 250},
	{"\u221A", 251},
	{"\u207F", 252},
	{"\u00B2", 253},
	{"\u25A0", 254},
	{"\u00A0", 255},
};

static void				print_endoom(t_wad_endoom *endoom)
{
	size_t			i;
	size_t const	size = sizeof(g_eascii_unicode) / sizeof(t_tablepair_int);

	i = 0;
	while (i < ANSI_SIZE)
	{	
		ft_termsetcolor(endoom->color[i] & 0x0F);
		ft_termsetcolorbg((endoom->color[i] & 0x80) >> 3);
		if (endoom->ascii[i] >= 128)
			ft_printf("%s", find_tablepair_int_id(g_eascii_unicode, size, endoom->ascii[i]));
		else
			ft_printf("%c", endoom->ascii[i]);
		if (i % 80 == 79)
			ft_putchar('\n');
		i++;
		ft_termresetcolor();
		ft_termresetcolorbg();
	}
}

static void				alloc_endoom(t_wad_general *wad_general)
{
	wad_general->endoom = (t_wad_endoom*)ft_memalloc(sizeof(t_wad_endoom));
	if (wad_general->endoom == NULL)
		error_msg_errno("Failed to allocate endoom");
}

static void				alloc_color(t_wad_endoom *endoom)
{
	endoom->ascii = (t_uint8*)ft_memalloc(sizeof(t_uint8) * ANSI_SIZE);
	if (endoom->ascii == NULL)
		error_msg_errno("Failed to allocate endoom ascii");
	endoom->color = (t_uint8*)ft_memalloc(sizeof(t_uint8) * ANSI_SIZE);
	if (endoom->color == NULL)
		error_msg_errno("Failed to allocate endoom colors");
}

static void				fill_wad_endoom(t_binary_read *wad_bin, t_wad_endoom *endoom)
{
	size_t			i;

	alloc_color(endoom);
	i = 0;
	while (i < ANSI_SIZE)
	{
		endoom->ascii[i] = read_char(wad_bin);
		endoom->color[i] = read_char(wad_bin);
		i++;
	}
}

void	parse_wad_endoom(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory)
{
	if (directory->size_lump == ANSI_SIZE * 2)
		alloc_endoom(wad_general);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid ENDOOM lump");
	wad_bin->content_pos = directory->loc_lump;
	fill_wad_endoom(wad_bin, wad_general->endoom);
	print_endoom(wad_general->endoom);
}
