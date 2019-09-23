/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_keystate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:14:43 by pholster       #+#    #+#                */
/*   Updated: 2019/09/03 13:52:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_hash.h"

#include "keymap.h"

/*
** * set_keystate will take the keymap, keysym and a state.
** * It will then set the state of the key to the given state.
** * If the key isn't monitored yet it will add the key to the monitored keys.
*/

t_bool	set_keystate(const t_hashmap *keymap, SDL_Keycode key, t_keystate state)
{
	t_keystate	*current;

	current = (t_keystate *)ft_hashmapget(keymap, &key, sizeof(key));
	if (current == NULL)
		current = new_keystate();
	*current = state;
	return (ft_hashmapadd(keymap, &key, sizeof(key), current));
}
