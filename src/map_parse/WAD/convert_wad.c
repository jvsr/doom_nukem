/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_wad.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/25 17:28:58 by pholster       #+#    #+#                */
/*   Updated: 2019/11/28 14:58:54 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "map.h"
#include "wad.h"
#include "game.h"
#include "error.h"

t_level *alloc_level(void)
{
	t_level *level;

	level = (t_level*)ft_memalloc(sizeof(t_level));
	if (level == NULL)
		error_msg_errno("Failed to alloc level");
	return (level);
}

t_level	*convert_wad(t_wad *wad, t_game *game)
{
	t_level	*level;

	level = alloc_level();
	convert_dssound(wad, game);
	return (level);
}
