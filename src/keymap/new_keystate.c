/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_keystate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/23 13:30:33 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:48:08 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "libft/ft_mem.h"

#include "keymap.h"
#include "error.h"

/*
** * (Internal function)
** * allocates memory for a keystate so it can be safely stored in the hashmap.
*/

t_keystate	*new_keystate(void)
{
	t_keystate	*new;

	new = (t_keystate *)ft_memalloc(sizeof(t_keystate));
	if (new == NULL)
		error_msg_errno("Failed to alloc keystate");
	return (new);
}
