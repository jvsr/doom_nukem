/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keymaptoggle.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:14:43 by pholster       #+#    #+#                */
/*   Updated: 2019/08/29 15:14:43 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "keymap.h"
#include "libft/ft_hash.h"

t_bool	keymaptoggle(const t_hashmap *keymap, SDL_Keycode key, t_bool pressed)
{
	t_keystate	state;

	state = keymapget(keymap, key);
	if (pressed == TRUE)
	{
		//state |= KEY_HELDDOWN;
		//state = KEY_HELDDOWN;
		//state &= ~(state & KEY_TOGGLED);
	}
	else
	{
		//state = 0;
	}
	return (keymapset(keymap, key, state));
}
