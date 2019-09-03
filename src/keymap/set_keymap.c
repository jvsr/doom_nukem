/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_keymap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 15:14:43 by pholster       #+#    #+#                */
/*   Updated: 2019/09/03 13:52:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "libft/ft_hash.h"
#include "libft/ft_memory.h"

#include "keymap.h"
#include "error.h"

/*
** * set keymap will take the keymap, keysym and a state.
** * It will then set the state of the key to the given state.
** * If the key isnt monitored yet it will add the key to the monitored keys.
*/

t_bool	set_keymap(const t_hashmap *keymap, SDL_Keycode key, t_keystate state)
{
	t_keystate	*current;

	current = ft_hashmapget(keymap, &key, sizeof(key));
	if (current == NULL)
		current = (t_keystate *)ft_memalloc(sizeof(t_keystate));
	if (current == NULL)
		error_msg(strerror(errno), errno);
	*current = state;
	return (ft_hashmapadd(keymap, &key, sizeof(key), current));
}
