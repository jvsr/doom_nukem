/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstate.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 20:40:08 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/14 11:45:54 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYSTATE_H
# define KEYSTATE_H

# include <SDL2/SDL_events.h>

typedef struct s_game			t_game;

void							mainmenu_eventstate
									(t_game *game, SDL_Event event);
void							missions_eventstate
									(t_game *game, SDL_Event event);
void							options_eventstate
									(t_game *game, SDL_Event event);
void							options_confirmation_eventstate
									(t_game *game, SDL_Event event);
void							controls_eventstate
									(t_game *game, SDL_Event event);
void							set_controls_eventstate
									(t_game *game, SDL_Event event);
void							map_editor_eventstate
									(t_game *game, SDL_Event event);
void							map_editor_select_eventstate
									(t_game *game, SDL_Event event);

typedef enum					e_eventstate_code
{
	mainmenu,
	missions,
	options,
	options_confirmation,
	controls,
	set_controls,
	map_editor,
	map_editor_select,
}								t_eventstate_code;

typedef union					u_types
{
	int		dgt;
	int		*dgtptr;
	void	*ptr;
}								t_types;

typedef struct					s_eventstate
{
	t_eventstate_code	eventstate;
	t_types				*arguments;
}								t_eventstate;

#endif
