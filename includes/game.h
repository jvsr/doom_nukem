/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   game.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 19:01:54 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/14 17:07:54 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <SDL2/SDL.h>

# include "libft/ft_bool.h"

# include "gametime.h"

typedef struct s_gui			t_gui;
typedef struct s_player			t_player;
typedef struct s_hashmap		t_hashmap;
typedef struct s_audio_man		t_audio_man;
typedef struct s_setting		t_setting;
typedef struct s_campaign		t_campaign;
typedef struct s_eventstate		t_eventstate;
typedef struct s_map			t_map;
typedef struct s_editor_map		t_editor_map;
typedef struct s_tpool			t_tpool;
typedef struct s_sector			t_sector;

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
	t_map			*map;
	t_editor_map	*editor_map;
	t_campaign		*campaign;
	t_player		*player;
	t_hashmap		*keymap;
	t_bool			cursoractive;
	t_time			starttime;
	t_audio_man		*audio_man;
	SDL_Surface		**textures;
	t_setting		*setting;
	t_eventstate	*cureventstate;
	t_tpool			*pool;
	t_uint64		frametime;
	t_uint64		lastframe;
}				t_game;

void			loop(t_game *game);
void			handle_event(t_game *game, SDL_Event event);
void			check_quit(t_game *game, SDL_Event event);
void			*display_splash(t_game *game, char *loc);
void			load_map(t_game *game, t_map *map, t_player *plyr);
void			loader(t_game *game);
void			quit(int exit_code);
int				get_sec_num(t_map *map, t_sector *sec);
void			shrink(t_map *map);

#endif
