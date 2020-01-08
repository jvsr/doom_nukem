/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_game.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:37:51 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/03 16:37:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "game.h"
#include "player.h"
#include "libft/ft_str.h"

void	loop_game(t_game *game)
{
	char *num;

	num = ft_strformat("Angle: %f", game->player->angle);
	set_elem_text_str(get_gui_child(game->ui, "angle"), num);
	// set_elem_redraw(get_gui_child(game->ui, "gameview"));
	ft_strdel(&num);
}
