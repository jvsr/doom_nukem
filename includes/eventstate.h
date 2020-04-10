/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 20:40:08 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/09 16:29:11 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTSTATE_H
# define EVENTSTATE_H

# include <SDL2/SDL_events.h>
# include <SDL2/SDL_thread.h>

typedef struct s_game	t_game;

void			initload_eventstate(t_game *game, SDL_Event event);
void			splash_eventstate(t_game *game, SDL_Event event);
void			mainmenu_eventstate(t_game *game, SDL_Event event);
void			missions_eventstate(t_game *game, SDL_Event event);
void			options_eventstate(t_game *game, SDL_Event event);
void			options_confirmation_eventstate(t_game *game, SDL_Event event);
void			controls_eventstate(t_game *game, SDL_Event event);
void			set_controls_eventstate(t_game *game, SDL_Event event);
void			map_editor_eventstate(t_game *game, SDL_Event event);
void			map_editor_select_eventstate(t_game *game, SDL_Event event);
void			hud_eventstate(t_game *game, SDL_Event event);
void			hud_options_eventstate(t_game *game, SDL_Event event);
void			eventstate_hud_died(t_game *game, SDL_Event event);
void			hud_win_eventstate(t_game *game, SDL_Event event);

typedef enum	e_eventstate_code
{
	initload,
	splash,
	mainmenu,
	missions,
	options,
	options_confirmation,
	controls,
	set_controls,
	map_editor,
	map_editor_select,
	hud,
	hud_options,
	hud_died,
	hud_win
}				t_eventstate_code;

typedef union	u_types
{
	int		dgt;
	int		*dgtptr;
	void	*ptr;
}				t_types;

typedef struct	s_eventstate
{
	SDL_mutex			*lock;
	t_eventstate_code	eventstate;
	t_types				*arguments;
}				t_eventstate;

#endif
