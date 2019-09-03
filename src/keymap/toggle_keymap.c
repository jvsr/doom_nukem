/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   toggle_keymap.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:14:43 by pholster       #+#    #+#                */
/*   Updated: 2019/09/03 13:52:24 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "libft/ft_hash.h"
#include "libft/ft_memory.h"

#include "error.h"
#include "keymap.h"

/*
** * toggle keymap will take the keymap, keysym and if the key is being pressed.
** * It will then based on the current state of the key change the state.
** * If the key is being pressed it toggles the toggle and sets helddown to 1.
** * if the key is not being pressed it sets helddown to 0.
** * If the key isnt monitored yet it will add the key to the monitored keys.
*/

t_bool	toggle_keymap(const t_hashmap *keymap, SDL_Keycode key, t_bool pressed)
{
	t_keystate	*current;

	current = ft_hashmapget(keymap, &key, sizeof(key));
	if (current == NULL)
		current = (t_keystate *)ft_memalloc(sizeof(t_keystate));
	if (current == NULL)
		error_msg(strerror(errno), errno);
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
