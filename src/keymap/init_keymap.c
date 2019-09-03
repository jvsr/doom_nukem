/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keymapinit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:54:55 by pholster       #+#    #+#                */
/*   Updated: 2019/09/03 13:51:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "game.h"
#include "error.h"
#include "libft/ft_hash.h"

t_bool	init_keymap(t_game *game)
{
	game->keymap = ft_hashmapnew(INIT_KEYMAP_SIZE, INIT_KEYMAP_ALGO);
	if (game->keymap == NULL)
		error_msg("keymap fialed to allocate\n", 1);
	return (game->keymap != NULL);
}
