/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   options.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 14:27:39 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/16 14:27:39 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "gui_config.h"

void	options_return(t_game *game, t_transform *gui)
{
	t_transform	*mainmenu;
	(void)gui;
	mainmenu = get_gui_child(game->ui, "mainmenu");
	del_elem_child(mainmenu, "options");
}
