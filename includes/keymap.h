/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keymap.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:35:51 by jvisser       #+#    #+#                 */
/*   Updated: 2019/11/08 22:45:52 by jvisser       ########   odam.nl         */
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
const char		*get_keystate_name(SDL_Keycode key);

t_bool			is_helddown(t_hashmap const *keymap, SDL_Keycode key);
t_bool			is_toggled(t_hashmap const *keymap, SDL_Keycode key);

#endif
