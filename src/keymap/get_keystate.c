/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_keystate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:14:43 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:48:20 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_hash.h"

#include "keymap.h"

/*
** * get_keystate will take the keymap and a keysym code.
** * It will then retrieve the state of the key.
** * If the key isn't monitored this function returns a state of 0.
*/

t_keystate	get_keystate(const t_hashmap *keymap, SDL_Keycode key)
{
	t_keystate	*value;

	value = (t_keystate *)ft_hashmapget(keymap, &key, sizeof(key));
	if (value == NULL)
		return (0);
	return (*value);
}
