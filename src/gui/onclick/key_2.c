/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 22:12:37 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/09 17:03:39 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"
#include "setting.h"
#include "keymap.h"

void	set_key_str(SDL_Keycode keycode, t_transform *self)
{
	const char	*keystate = get_keystate_name(keycode);

	set_elem_text_str(self, keystate);
	ft_strdel((char**)&keystate);
}
