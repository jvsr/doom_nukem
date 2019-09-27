/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_keystate_all.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/31 15:09:51 by pholster       #+#    #+#                */
/*   Updated: 2019/09/03 13:52:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_hash.h"

#include "keymap.h"

/*
** * set_keystate_all will take the keymap and a state.
** * It will then change the state of every monitored key to the given state.
*/

void		set_keystate_all(const t_hashmap *keymap, t_keystate state)
{
	size_t		i;
	t_hashlist	*current;
	t_keystate	*value;

	i = 0;
	while (i < keymap->size)
	{
		current = keymap->arr[i];
		while (current != NULL)
		{
			value = (t_keystate *)current->value;
			*value = state;
			current = current->next;
		}
		i++;
	}
}
