/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_eventstate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:46:05 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:46:11 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_thread.h>

#include "libft/ft_mem.h"

#include "game.h"
#include "error.h"
#include "eventstate.h"

void	init_eventstate(t_game *game)
{
	t_eventstate	*cureventstate;

	cureventstate = ft_memalloc(sizeof(t_eventstate));
	if (cureventstate == NULL)
		error_msg_errno("Failed to alloc eventstate");
	cureventstate->lock = SDL_CreateMutex();
	if (cureventstate->lock == NULL)
		error_msg_errno("Failed to alloc eventstate mutex lock");
	cureventstate->eventstate = initload;
	game->cureventstate = cureventstate;
}
