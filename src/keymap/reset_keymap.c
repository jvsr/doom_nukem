/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reset_keymap.c                                     :+:    :+:            */
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
** * reset_keymap will take the keymap.
** * It will then reset the state of every monitored key to 0.
*/

void	reset_keymap(const t_hashmap *keymap)
{
	set_keystate_all(keymap, 0);
}
