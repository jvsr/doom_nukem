/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstates.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 21:12:51 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/09 21:26:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "gui.h"
#include "game.h"
#include "keymap.h"
#include "onclick.h"
#include "keystate.h"

void	mainmenu_eventstate(t_game *game, SDL_Event event)
{
	(void)game;
	(void)event;
}

void	options_eventstate(t_game *game, SDL_Event event)
{
	(void)game;
	(void)event;
}

/*
**	Arguments:
**	[0]: dgtptr, location of the to-set control
**	[1]: t_transform*, location of the keychange element
**	[2]: t_transform*, location of the controlsbutton element
*/
void	set_controls_eventstate(t_game *game, SDL_Event event)
{
	static t_bool	first = TRUE;

	if (first == FALSE
	&& (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN))
	{
		if (event.type == SDL_KEYDOWN)
			*game->cureventstate->arguments[0].dgtptr = event.key.keysym.sym;
		else
			*game->cureventstate->arguments[0].dgtptr = event.button.button;
		set_elem_show_clickable(
			(t_transform*)game->cureventstate->arguments[1].ptr, FALSE);
		set_key_str(*game->cureventstate->arguments[0].dgtptr,
			(t_transform*)game->cureventstate->arguments[2].ptr);
		game->cureventstate->eventstate = options;
		free(game->cureventstate->arguments);
		first = TRUE;
	}
	else
		first = FALSE;
}
