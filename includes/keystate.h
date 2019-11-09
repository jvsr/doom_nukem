/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keystate.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 20:40:08 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/09 19:50:33 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYSTATE_H
# define KEYSTATE_H

# include <SDL2/SDL_events.h>

typedef struct s_game	t_game;
typedef void			(t_eventstate_fnc)(t_game *, SDL_Event);

void					mainmenu_eventstate(t_game *game, SDL_Event event);
void					options_eventstate(t_game *game, SDL_Event event);
void					set_controls_eventstate(t_game *game, SDL_Event event);

static t_eventstate_fnc	*g_eventstate[] =
{
	mainmenu_eventstate,
	options_eventstate,
	set_controls_eventstate,
};

typedef enum			e_eventstate_code
{
	mainmenu,
	options,
	set_controls,
}						t_eventstate_code;

typedef union			u_types
{
	int		dgt;
	int		*dgtptr;
	void	*ptr;
}						t_types;

typedef struct			s_eventstate
{
	t_eventstate_code	eventstate;
	t_types				*arguments;
}						t_eventstate;

#endif
