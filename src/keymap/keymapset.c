/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keymapset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:14:43 by pholster       #+#    #+#                */
/*   Updated: 2019/08/29 15:14:43 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "keymap.h"
#include "libft/ft_hash.h"

t_bool	keymapset(const t_hashmap *keymap, SDL_Keycode key, t_keystate state)
{
	t_keystate	copy_state;

	copy_state = state;
	return (ft_hashmapadd(keymap, &key, sizeof(key), &copy_state));
}
