/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   eventstates.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 21:12:51 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/07 23:03:54 by jvisser       ########   odam.nl         */
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

void	set_controls_eventstate(t_game *game, SDL_Event event)
{
	(void)game;
	(void)event;
	printf("cur forwardkey: %d\n", *game->cureventstate->arguments[0].dgtptr);
	*(game->cureventstate->arguments[0].dgtptr) = 'w';
	printf("cur forwardkey: %d\n", *game->cureventstate->arguments[0].dgtptr);
}
