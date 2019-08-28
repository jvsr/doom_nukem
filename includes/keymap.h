/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keymap.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:35:51 by jvisser        #+#    #+#                */
/*   Updated: 2019/08/27 15:13:06 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

# include <SDL2/SDL.h>

typedef struct	s_keypair
{
	const char	*name;
	SDL_Keycode	key;
}				t_keypair;

#endif