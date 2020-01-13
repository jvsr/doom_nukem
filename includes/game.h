/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 19:01:54 by pholster       #+#    #+#                */
/*   Updated: 2019/11/28 15:15:45 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <SDL2/SDL.h>

# include "libft/ft_bool.h"

# include "gametime.h"

typedef struct s_gui			t_gui;
typedef struct s_level			t_level;
typedef struct s_player			t_player;
typedef struct s_hashmap		t_hashmap;
typedef struct s_audio_man		t_audio_man;
typedef struct s_setting		t_setting;
typedef struct s_campaign		t_campaign;
typedef struct s_eventstate		t_eventstate;
typedef struct s_map			t_map;

typedef	enum	e_state
{
	running,
	suspended,
	stopped
}				t_state;

typedef struct	s_game
{
	char			*exec_path;
	char			*exec_name;
	char			**envp;
	char			**argv;
	t_state			state;
	SDL_Window		*window;
	SDL_Surface		*surface;
	t_gui			*ui;
	t_level			*level;
	t_map			*map;
	t_campaign		*campaign;
	t_player		*player;
	t_hashmap		*keymap;
	t_bool			cursoractive;
	t_time			starttime;
	t_audio_man		*audio_man;
	SDL_Surface		**textures;
	t_setting		*setting;
	t_eventstate	*cureventstate;
}				t_game;

void			loop(t_game *game);
void			display_splash(t_game *game, char *loc);
void			loader(t_game *game);
void			quit(int exit_code);

#endif
