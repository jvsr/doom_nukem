/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   toggle_keystate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:14:43 by pholster       #+#    #+#                */
/*   Updated: 2019/09/03 13:52:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_hash.h"
#include "libft/ft_mem.h"

#include "keymap.h"

/*
** * toggle_keystate will take the keymap, keysym and if it's being pressed.
** * It will then based on the current state of the key change the state.
** * If the key is being pressed it toggles the toggle and sets helddown to 1.
** * if the key is not being pressed it sets helddown to 0.
** * If the key isn't monitored yet it will add the key to the monitored keys.
*/

t_bool	toggle_keystate(const t_hashmap *keymap, SDL_Keycode key,
						t_bool pressed)
{
	t_keystate	*current;

	current = (t_keystate *)ft_hashmapget(keymap, &key, sizeof(key));
	if (current == NULL)
		current = new_keystate();
	if (pressed == TRUE)
	{
		*current |= KEY_HELDDOWN;
		*current ^= KEY_TOGGLED;
	}
	else
	{
		*current &= ~KEY_HELDDOWN;
	}
	return (ft_hashmapadd(keymap, &key, sizeof(key), current));
}
