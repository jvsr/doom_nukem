/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_playpal.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 12:05:42 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/21 20:01:51 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define PALETTE_SIZE 768

// static void				print_playpal(t_wad_playpal *playpal)
// {
// 	size_t i;

// 	i = 0;
// 	while (i < playpal->color_amount)
// 	{
// 		printf("I:%zu, R:%d, G:%d, B:%d\n",
// 			i,
// 			playpal->color[i].r,
// 			playpal->color[i].g,
// 			playpal->color[i].b);
// 		i++;
// 	}
// }

static void		alloc_playpal(t_wad_general *wad_general, size_t palette_amount)
{
	size_t	i;

	wad_general->playpal_amount = palette_amount;
	wad_general->playpal = (t_wad_playpal**)ft_memalloc(sizeof(t_wad_playpal*) * palette_amount);
	if (wad_general->playpal == NULL)
		error_msg_errno("Failed to allocate playpal");
	i = 0;
	while (i < palette_amount)
	{
		wad_general->playpal[i] = (t_wad_playpal*)ft_memalloc(sizeof(t_wad_playpal));
		if (wad_general->playpal[i] == NULL)
			error_msg_errno("Failed to allocate playpal single");
		i++;
	}
}

static void		alloc_color(t_wad_playpal *playpal, size_t color_amount)
{
	playpal->color_amount = color_amount;
	playpal->color = (SDL_Color*)ft_memalloc(sizeof(SDL_Color) * playpal->color_amount);
	if (playpal->color == NULL)
			error_msg_errno("Failed to allocate playpal colors");
}

static void		fill_wad_playpal(t_binary_read *wad_bin, t_wad_playpal *playpal)
{
	size_t			i;

	alloc_color(playpal, PALETTE_SIZE / 3);
	i = 0;
	while (i < playpal->color_amount)
	{
		playpal->color[i].r = read_char(wad_bin);
		playpal->color[i].g = read_char(wad_bin);
		playpal->color[i].b = read_char(wad_bin);
		i++;
	}
}

void			parse_wad_playpal(t_binary_read *wad_bin, t_wad_general *wad_general, t_wad_directory *directory)
{
	size_t	i;

	if (directory->size_lump % PALETTE_SIZE == 0)
		alloc_playpal(wad_general, directory->size_lump / PALETTE_SIZE);
	else
		error_msg("Failed to parse WAD map", 25, "Invalid PLAYPAL lump");
	i = 0;
	while (i < wad_general->playpal_amount)
	{
		wad_bin->content_pos = directory->loc_lump + i * PALETTE_SIZE;
		fill_wad_playpal(wad_bin, wad_general->playpal[i]);
		// print_playpal(wad_general->playpal[i]);
		i++;
	}
}
