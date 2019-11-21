/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_eventstate.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/12 17:46:05 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/12 17:47:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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
	cureventstate->eventstate = mainmenu;
	cureventstate->arguments = NULL;
	game->cureventstate = cureventstate;
}
