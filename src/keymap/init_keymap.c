/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_keymap.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:54:55 by pholster       #+#    #+#                */
/*   Updated: 2019/09/03 13:51:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "libft/ft_hash.h"

#include "gui.h"
#include "init.h"
#include "game.h"
#include "error.h"

/*
** * init_keymap will take the game struct.
** * It will then allocate space for the keymap defined by INIT_KEYMAP_SIZE.
** * And then set the hashing algorithm to the one defined by INIT_KEYMAP_ALGO.
** * If the allocation failed the program will exit.
*/

void	init_keymap(t_game *game)
{
	game->keymap = ft_hashmapnew(INIT_KEYMAP_SIZE, INIT_KEYMAP_ALGO);
	if (game->keymap == NULL)
		error_msg_errno("Failed to alloc keymap");
}
