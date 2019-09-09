/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 19:01:54 by pholster       #+#    #+#                */
/*   Updated: 2019/09/09 16:16:54 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <SDL2/SDL_video.h>
# include <SDL2/SDL_surface.h>

typedef struct s_ui			t_ui;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_hashmap	t_hashmap;

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
	t_ui		*ui;
	t_map		*map;
	t_player	*player;
	t_hashmap	*keymap;
}				t_game;

void			loop(t_game *game);

#endif
