/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keymapinit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:54:55 by pholster       #+#    #+#                */
/*   Updated: 2019/08/31 15:10:28 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "keymap.h"
#include "game.h"
#include "error.h"
#include "libft/ft_hash.h"

t_bool	keymapinit(t_game *game)
{
	game->keymap = ft_hashmapnew(KEYMAP_SIZE, KEYMAP_HASHF);
	if (game->keymap == NULL)
		error_msg("Error: keymap fialed to allocate\n", 1);
	return (game->keymap != NULL);
}
