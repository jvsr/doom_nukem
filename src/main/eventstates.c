/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstates.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 21:12:51 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/08 13:52:34 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_events.h>

#include "game.h"
#include "keymap.h"
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
*/
void	set_controls_eventstate(t_game *game, SDL_Event event)
{
	static t_bool	first = TRUE;

	printf("cur forwardkey: %d\n", *game->cureventstate->arguments[0].dgtptr);
	if (first == FALSE && (event.type == SDL_KEYDOWN || event.type == SDL_MOUSEBUTTONDOWN))
	{
		if (event.type == SDL_KEYDOWN)
			*game->cureventstate->arguments[0].dgtptr = event.key.keysym.sym;
		else
			*game->cureventstate->arguments[0].dgtptr = event.button.button;
		game->cureventstate->eventstate = options;
		free(game->cureventstate->arguments);
		first = TRUE;
	}
	else
		first = FALSE;
	
	printf("cur forwardkey: %d\n", *game->cureventstate->arguments[0].dgtptr);
}
