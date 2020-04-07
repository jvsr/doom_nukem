/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_panel.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 13:48:38 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:11:51 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"

/*
** * Gui internal function
*/

void		draw_panel(t_panel *panel, t_game *game)
{
	draw_elements(panel->children, game);
}
