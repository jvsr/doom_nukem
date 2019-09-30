/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keymap.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:35:51 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/03 13:51:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

# include <SDL2/SDL_keycode.h>

# include "libft/ft_bool.h"

# define KEY_HELDDOWN 0x01
# define KEY_TOGGLED 0x02

typedef	struct s_game		t_game;
typedef	struct s_hashmap	t_hashmap;
typedef	unsigned char		t_keystate;

/*
** t_keypair is only used for keymapprint which is a debug func
*/

typedef struct	s_keypair
{
	const char	*name;
	SDL_Keycode	key;
}				t_keypair;

t_keystate		*new_keystate(void);
void			reset_keymap(const t_hashmap *keymap);
void			clear_keymap(const t_hashmap *keymap);
void			print_keymap(const t_hashmap *keymap);
t_keystate		get_keystate(const t_hashmap *keymap, SDL_Keycode key);
void			set_keystate_all(const t_hashmap *keymap, t_keystate state);
t_bool			toggle_keystate(const t_hashmap *keymap, SDL_Keycode key,
					t_bool pressed);
t_bool			set_keystate(const t_hashmap *keymap, SDL_Keycode key,
					t_keystate state);

#endif
