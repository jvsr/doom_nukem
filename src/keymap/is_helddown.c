/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_helddown.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/08 17:30:51 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:48:10 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"

#include "keymap.h"

t_bool	is_helddown(t_hashmap const *keymap, SDL_Keycode key)
{
	return (get_keystate(keymap, key) & KEY_HELDDOWN);
}
