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
#include "init.h"

/*
** ---------------------------------init_keymap---------------------------------
*/

Test(init_keymap, null, .signal=SIGSEGV)
{
	init_keymap(NULL);
}

Test(init_keymap, succsess)
{
	t_game *game;

	game = (t_game *)ft_memalloc(sizeof(t_game));
	init_keymap(game);
	cr_assert(game->keymap != NULL);
}

/*
** ---------------------------------get_keymap----------------------------------
*/

Test(get_keymap, null, .signal=SIGSEGV)
{
	get_keymap(NULL, 0);
}

// Test(get_keymap, null_keystate)
// {
// 	t_keystate	state;
// 	t_hashmap	*keymap;

// 	keymap = ft_hashmapnew(5, INIT_KEYMAP_ALGO);
// 	state = get_keymap(keymap, 42);
// 	cr_assert(state == 0);
// }

// Test(get_keymap, first_key)
// {
// 	SDL_Keycode	key;
// 	t_keystate	state;
// 	t_hashmap	*keymap;

// 	keymap = ft_hashmapnew(3, INIT_KEYMAP_ALGO);

// 	key = 21;
// 	state = 3;
// 	ft_hashmapadd(keymap, &key, sizeof(key), &state);

// 	state = get_keymap(keymap, 21);
// 	cr_assert(state == 3);
// }

Test(get_keymap, last_key)
{
	SDL_Keycode	key;
	t_keystate	state;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(1, INIT_KEYMAP_ALGO);

	key = 1;
	state = 3;
	ft_hashmapadd(keymap, &key, sizeof(key), &state);

	key = 2;
	state = 1;
	ft_hashmapadd(keymap, &key, sizeof(key), &state);

	key = 3;
	state = 2;
	ft_hashmapadd(keymap, &key, sizeof(key), &state);

	state = get_keymap(keymap, 1);
	ft_putnum(state);
	cr_assert(state == 3);
}
