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

#include "libft/ft_str.h"

#include "gui.h"
#include "game.h"
#include "player.h"

void		loop_game(t_game *game)
{
	t_bool	redraw;
	char	*elem_text;

	redraw = player_move(game->player, game->keymap);
	elem_text = ft_strformat("Angle: %.2f\nPos: %.2f %.2f",
		game->player->angle, game->player->pos.x, game->player->pos.y);
	set_elem_text_str(get_gui_child(game->ui, "angle"), elem_text);
	if (redraw == TRUE)
		set_elem_redraw(get_gui_child(game->ui, "gameview"));
	ft_strdel(&elem_text);
}
