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

static t_keystate	*new_state(t_keystate state)
{
	t_keystate	*new_state;

	new_state = (t_keystate *)ft_memalloc(sizeof(t_keystate));
	*new_state = state;
	return (new_state);
}

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

Test(get_keymap, null_keystate)
{
	t_keystate	state;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(5, INIT_KEYMAP_ALGO);
	state = get_keymap(keymap, 42);
	cr_assert(state == 0);
}

Test(get_keymap, first_key)
{
	SDL_Keycode	key;
	t_keystate	state;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(1, INIT_KEYMAP_ALGO);

	key = 21;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(3));

	key = 12;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(6));

	state = get_keymap(keymap, 21);
	cr_assert(state == 3);
}

Test(get_keymap, middle_key)
{
	SDL_Keycode	key;
	t_keystate	state;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(1, INIT_KEYMAP_ALGO);

	key = 8;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(1));

	key = 16;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(10));

	key = 24;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(20));

	state = get_keymap(keymap, 16);
	cr_assert(state == 10);
}

Test(get_keymap, last_key)
{
	SDL_Keycode	key;
	t_keystate	state;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(1, INIT_KEYMAP_ALGO);

	key = 1;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(12));

	key = 12;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(24));

	key = 123;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(36));

	state = get_keymap(keymap, 123);
	cr_assert(state == 36);
}

/*
** ---------------------------------get_keymap----------------------------------
*/
