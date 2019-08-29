/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keymapget.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:14:43 by pholster       #+#    #+#                */
/*   Updated: 2019/08/29 15:14:43 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "keymap.h"
#include "libft/ft_hash.h"

t_keystate	keymapget(const t_hashmap *keymap, SDL_Keycode key)
{
	t_keystate	*value;

	value = ft_hashmapget(keymap, &key, sizeof(key));
	if (value == NULL)
		return (0);
	return (*value);
}
