/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_keymap.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/09 17:48:09 by pholster       #+#    #+#                */
/*   Updated: 2019/09/09 17:48:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_hash.h"

#include "keymap.h"

/*
** * clear_keymap will take the keymap.
** * It will then delete all monitored keys.
*/

void	clear_keymap(const t_hashmap *keymap)
{
	size_t		i;
	t_hashlist	*current;
	t_hashlist	*next;

	i = 0;
	while (i < keymap->size)
	{
		current = keymap->arr[i];
		while (current != NULL)
		{
			next = current->next;
			free(current->key);
			free(current->value);
			free(current);
			current = next;
		}
		keymap->arr[i] = NULL;
		i++;
	}
}
