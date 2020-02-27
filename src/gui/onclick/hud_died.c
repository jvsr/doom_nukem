/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hud_died.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 12:33:27 by ehollidg       #+#    #+#                */
/*   Updated: 2020/02/27 12:33:27 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "eventstate.h"
#include "game.h"
#include "gui.h"

void		hud_diedmainmenu(t_game *game, t_transform *gui)
{
	(void)gui;
	game->cureventstate->eventstate = mainmenu;
	set_elem_show_clickable(get_gui_child(game->ui, "hud_died"), FALSE);
	set_elem_show_clickable(get_gui_child(game->ui, "mainmenu"), TRUE);
}
