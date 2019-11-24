/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_wad_reject.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/23 16:59:26 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/23 18:21:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"
#include "libft/ft_mem.h"
#include "libft/ft_printf.h" //

#include "wad.h"
#include "error.h"
#include "serializer.h"

#define REJECT_SIZE (level->sectors_amount)

// static void	print_reject(unsigned char reject, t_wad_level *level, size_t i)
// {
// 	ft_printf("%d ", reject);
// 	if (i % REJECT_SIZE == REJECT_SIZE - 1)
// 		ft_putstr("\n");
// }

static void	alloc_reject(t_wad_level *level, size_t reject_amount)
{
	size_t	i;

	level->reject = (unsigned char**)ft_memalloc(sizeof(unsigned char*) * reject_amount + 1);
	if (level->reject == NULL)
		error_msg_errno("Failed to alloc level reject");
	i = 0;
	while (i < reject_amount + 1)
	{
		level->reject[i] = (unsigned char*)ft_memalloc(sizeof(unsigned char) * reject_amount + 1);
		if (level->reject[i] == NULL)
			error_msg_errno("Failed to alloc level reject");
		i++;
	}
}

void	parse_wad_reject(t_binary_read *wad_bin, t_wad_level *level, t_wad_directory *directory)
{
	char	c;
	size_t	i;

	alloc_reject(level, REJECT_SIZE);
	wad_bin->content_pos = directory->loc_lump;
	i = 0;
	while (i < REJECT_SIZE * REJECT_SIZE)
	{
		c = read_char(wad_bin);
		level->reject[i / REJECT_SIZE][i % REJECT_SIZE] = (c & 0b10000000) >> 7;
		// print_reject(level->reject[i / REJECT_SIZE][i % REJECT_SIZE], level, i);

		level->reject[(i + 1) / REJECT_SIZE][(i + 1) % REJECT_SIZE] = (c & 0b01000000) >> 6;
		// print_reject(level->reject[(i + 1) / REJECT_SIZE][(i + 1) % REJECT_SIZE], level, i + 1);

		level->reject[(i + 2) / REJECT_SIZE][(i + 2) % REJECT_SIZE] = (c & 0b00100000) >> 5;
		// print_reject(level->reject[(i + 2) / REJECT_SIZE][(i + 2) % REJECT_SIZE], level, i + 2);

		level->reject[(i + 3) / REJECT_SIZE][(i + 3) % REJECT_SIZE] = (c & 0b00010000) >> 4;
		// print_reject(level->reject[(i + 3) / REJECT_SIZE][(i + 3) % REJECT_SIZE], level, i + 3);

		level->reject[(i + 4) / REJECT_SIZE][(i + 4) % REJECT_SIZE] = (c & 0b00001000) >> 3;
		// print_reject(level->reject[(i + 4) / REJECT_SIZE][(i + 4) % REJECT_SIZE], level, i + 4);

		level->reject[(i + 5) / REJECT_SIZE][(i + 5) % REJECT_SIZE] = (c & 0b00000100) >> 2;
		// print_reject(level->reject[(i + 5) / REJECT_SIZE][(i + 5) % REJECT_SIZE], level, i + 5);

		level->reject[(i + 6) / REJECT_SIZE][(i + 6) % REJECT_SIZE] = (c & 0b00000010) >> 1;
		// print_reject(level->reject[(i + 6) / REJECT_SIZE][(i + 6) % REJECT_SIZE], level, i + 6);

		level->reject[(i + 7) / REJECT_SIZE][(i + 7) % REJECT_SIZE] = (c & 0b00000001);
		// print_reject(level->reject[(i + 7) / REJECT_SIZE][(i + 7) % REJECT_SIZE], level, i + 7);
		
		// ft_printf("%d", REJECT_SIZE * REJECT_SIZE, REJECT_SIZE);
		i += 8;
	}
}