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

static size_t		test_hash_algo(const void *key, size_t key_size)
{
	SDL_Keycode	temp;

	(void)key_size;
	temp = *((SDL_Keycode *)key);
	return (temp % 10);
}

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
	t_game 		*game;

	game = (t_game *)ft_memalloc(sizeof(t_game));
	init_keymap(game);

	cr_assert(game->keymap != NULL);
	cr_assert(game->keymap->size == INIT_KEYMAP_SIZE);
	cr_assert(game->keymap->f == INIT_KEYMAP_ALGO);
	cr_assert(game->keymap->arr != NULL);
}

/*
** --------------------------------get_keystate---------------------------------
*/

Test(get_keystate, null, .signal=SIGSEGV)
{
	get_keystate(NULL, 1);
}

Test(get_keystate, not_monitored)
{
	t_keystate	state;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(5, test_hash_algo);
	state = get_keystate(keymap, 42);
	cr_assert(state == 0);
}

Test(get_keystate, first_key)
{
	SDL_Keycode	key;
	t_keystate	state;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(3, test_hash_algo);

	key = 21;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(3));

	key = 11;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(6));

	state = get_keystate(keymap, 21);
	cr_assert(state == 3);
}

Test(get_keystate, middle_key)
{
	SDL_Keycode	key;
	t_keystate	state;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(3, test_hash_algo);

	key = 8;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(1));

	key = 18;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(10));

	key = 28;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(100));

	state = get_keystate(keymap, 18);
	cr_assert(state == 10);
}

Test(get_keystate, last_key)
{
	SDL_Keycode	key;
	t_keystate	state;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(3, test_hash_algo);

	key = 2;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(4));

	key = 202;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(8));

	key = 20302;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(16));

	state = get_keystate(keymap, 20302);
	cr_assert(state == 16);
}

/*
** --------------------------------set_keystate---------------------------------
*/

Test(set_keystate, null, .signal=SIGSEGV)
{
	set_keystate(NULL, 1, 3);
}

Test(set_keystate, not_monitored)
{
	SDL_Keycode	key;
	t_keystate	*value;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(1, test_hash_algo);

	key = 42;
	set_keystate(keymap, key, 12);

	value = ft_hashmapget(keymap, &key, sizeof(key));
	cr_assert(*value == 12);
}

Test(set_keystate, add_last)
{
	SDL_Keycode	key;
	t_keystate	*value;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(3, test_hash_algo);

	key = 33;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(64));

	key = 333;
	set_keystate(keymap, key, 124);

	value = ft_hashmapget(keymap, &key, sizeof(key));
	cr_assert(*value == 124);
}

Test(set_keystate, replace)
{
	SDL_Keycode	key;
	t_keystate	*value;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(1, test_hash_algo);

	key = 1;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(0));

	key = 2;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(0));

	key = 1;
	set_keystate(keymap, key, 244);

	value = ft_hashmapget(keymap, &key, sizeof(key));
	cr_assert(*value == 244);
}

Test(set_keystate, replace_middle)
{
	SDL_Keycode	key;
	t_keystate	*value;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(2, test_hash_algo);

	key = 1;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(0));

	key = 11;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(0));

	key = 111;
	ft_hashmapadd(keymap, &key, sizeof(key), new_state(0));

	key = 11;
	set_keystate(keymap, key, 122);

	value = ft_hashmapget(keymap, &key, sizeof(key));
	cr_assert(*value == 122);
}

/*
** -------------------------------toggle_keystate-------------------------------
*/

Test(toggle_keystate, null, .signal=SIGSEGV)
{
	toggle_keystate(NULL, 1, FALSE);
}

Test(toggle_keystate, not_monitored)
{
	SDL_Keycode	key;
	t_keystate	*value;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(1, test_hash_algo);

	key = 25;
	toggle_keystate(keymap, key, TRUE);

	value = ft_hashmapget(keymap, &key, sizeof(key));
	cr_assert(*value == (KEY_HELDDOWN | KEY_TOGGLED));
}

Test(toggle_keystate, monitored)
{
	SDL_Keycode	key;
	t_keystate	*value;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(3, test_hash_algo);

	key = 606;
	set_keystate(keymap, key, KEY_HELDDOWN | KEY_TOGGLED);

	toggle_keystate(keymap, key, FALSE);

	value = ft_hashmapget(keymap, &key, sizeof(key));
	cr_assert(*value == KEY_TOGGLED);
}


Test(toggle_keystate, toggle_off)
{
	SDL_Keycode	key;
	t_keystate	*value;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(3, test_hash_algo);

	key = 606;
	set_keystate(keymap, key, KEY_TOGGLED);

	toggle_keystate(keymap, key, TRUE);

	value = ft_hashmapget(keymap, &key, sizeof(key));
	cr_assert(*value == KEY_HELDDOWN);
}

Test(toggle_keystate, all_off)
{
	SDL_Keycode	key;
	t_keystate	*value;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(3, test_hash_algo);

	key = 505;
	set_keystate(keymap, key, KEY_HELDDOWN);

	toggle_keystate(keymap, key, FALSE);

	value = ft_hashmapget(keymap, &key, sizeof(key));
	cr_assert(*value == 0);
}

/*
** ------------------------------set_keystate_all-------------------------------
*/

Test(set_keystate_all, null, .signal=SIGSEGV)
{
	set_keystate_all(NULL, 2);
}

Test(set_keystate_all, nothing_monitored)
{
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(5, test_hash_algo);

	set_keystate_all(keymap, 42);
}

Test(set_keystate_all, set_multipale)
{
	size_t		i;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(4, test_hash_algo);

	for (int i = 0; i < 10; i++)
		set_keystate(keymap, i, KEY_HELDDOWN | KEY_TOGGLED);

	set_keystate_all(keymap, 42);
	for (int i = 0; i < 10; i++)
		cr_assert(get_keystate(keymap, i) == 42);
}

/*
** --------------------------------reset_keymap---------------------------------
*/

Test(reset_keymap, null, .signal=SIGSEGV)
{
	reset_keymap(NULL);
}

Test(reset_keymap, nothing_monitored)
{
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(6, test_hash_algo);

	reset_keymap(keymap);
}

Test(reset_keymap, set_multipale)
{
	size_t		i;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(7, test_hash_algo);

	for (int i = 0; i < 9; i++)
		set_keystate(keymap, i, 42);

	reset_keymap(keymap);
	for (int i = 0; i < 9; i++)
		cr_assert(get_keystate(keymap, i) == 0);
}

/*
** --------------------------------clear_keymap---------------------------------
*/

Test(clear_keymap, null, .signal=SIGSEGV)
{
	clear_keymap(NULL);
}

Test(clear_keymap, nothing_monitored)
{
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(5, test_hash_algo);

	clear_keymap(keymap);
}

Test(clear_keymap, reset_multipale)
{
	size_t		i;
	t_hashmap	*keymap;

	keymap = ft_hashmapnew(8, test_hash_algo);

	for (int i = 0; i < 12; i++)
		set_keystate(keymap, i, 42);

	clear_keymap(keymap);
	for (int i = 0; i < keymap->size; i++)
		cr_assert(keymap->arr[i] == NULL);
}
