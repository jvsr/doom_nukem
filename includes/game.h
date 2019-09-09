/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 19:01:54 by pholster       #+#    #+#                */
/*   Updated: 2019/09/09 11:56:12 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <SDL2/SDL.h>

typedef struct s_gui		t_gui;
typedef struct s_level		t_level;
typedef struct s_player		t_player;
typedef struct s_hashmap	t_hashmap;
typedef struct s_pixel		t_pixel;

typedef	enum	e_state
{
	running,
	suspended,
	stopped
}				t_state;

typedef struct	s_game
{
	t_state		state;
	SDL_Window	*window;
	SDL_Surface	*surface;
	t_gui		ui;
	t_level		*level;
	t_player	*player;
	t_hashmap	*keymap;
}				t_game;

void	loop(t_game *game);
void	sdl_surface_merge(SDL_Surface *dst, SDL_Surface *src, t_pixel start);
void	sdl_surface_merge_alpha(SDL_Surface *dst, SDL_Surface *src,
		t_pixel start);

#endif
