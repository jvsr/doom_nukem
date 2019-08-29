/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keymap.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:35:51 by jvisser        #+#    #+#                */
/*   Updated: 2019/08/29 00:00:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

# include <SDL2/SDL.h>
# include "libft/ft_bool.h"

# define KEYMAP_SIZE	21
# define KEYMAP_HASHF	ft_hashdjb2a
# define KEY_HELDDOWN	0x01
# define KEY_TOGGLED	0x02

typedef	struct s_game		t_game;
typedef	struct s_hashmap	t_hashmap;
typedef	char				t_keystate;

/*
** t_keypair is only used for keymapprint which is a debug func
*/
typedef struct	s_keypair
{
	const char	*name;
	SDL_Keycode	key;
}				t_keypair;

t_bool			keymapinit(t_game *game);
t_bool			keymapprint(const t_hashmap *keymap);
t_keystate		keymapget(const t_hashmap *keymap, SDL_Keycode key);
t_bool			keymaptoggle(const t_hashmap *keymap, SDL_Keycode key,
					t_bool pressed);
t_bool			keymapset(const t_hashmap *keymap, SDL_Keycode key,
					t_keystate state);

#endif
