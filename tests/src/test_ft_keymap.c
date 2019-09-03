/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_keymap.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/03 17:25:48 by pholster       #+#    #+#                */
/*   Updated: 2019/09/03 17:25:48 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <signal.h>

#include "libft/libft.h"

#include "keymap.h"
#include "game.h"

/*
** --------------------------------init_hashmap---------------------------------
*/

Test(init_hashmap, null, .signal=SIGSEGV)
{
	init_keymap(NULL);
}

Test(init_hashmap, succsess)
{
	t_game *game;

	game = (t_game *)ft_memalloc(sizeof(t_game));
	init_keymap(game);
	cr_assert(game->keymap != NULL);
}
