/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_gui.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 16:09:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 17:33:28 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"
#include "sdl_extra.h"

void			draw_gui(t_gui *ui, t_game *game)
{
	if (ui->redraw == FALSE)
		return ;
	sdl_clear_surface(ui->window_surface);
	draw_elements(ui->children, game);
	ui->redraw = FALSE;
}
