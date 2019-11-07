/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   controls.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 22:10:12 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/07 23:03:46 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "gui.h"
#include "game.h"
#include "setting.h"
#include "keystate.h"

void	controls_set_forward(t_game *game, t_transform *gui)
{
	t_types	*arguments;
	
	(void)gui;
	(void)game;
	game->cureventstate->eventstate = set_controls;
	arguments = ft_memalloc(sizeof(t_types*) * 1);
	arguments[0] = (t_types)&game->setting->controls.forward;
	game->cureventstate->arguments = arguments;

	printf("%d\n", *(arguments[0].dgtptr));
}
