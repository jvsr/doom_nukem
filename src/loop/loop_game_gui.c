/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_game_gui.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 14:31:35 by euan          #+#    #+#                 */
/*   Updated: 2020/04/14 20:43:45 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"
#include "game.h"
#include "player.h"

static void		health(t_game *game)
{
	static t_uint32	prev_health = -1;
	char			*text;

	if (prev_health == game->player->health)
		return ;
	text = ft_strformat("Health: %i/%i\n",
		game->player->health, PLAYER_MAX_HEALTH);
	set_elem_text_str(
		get_gui_child(game->ui, "hudInfoHp"), text);
	ft_strdel(&text);
	set_elem_redraw(get_gui_child(game->ui, "hudInfo"));
	prev_health = game->player->health;
}

static void		ammo(t_game *game)
{
	static t_uint32	prev_ammo = -1;
	char			*text;

	if (prev_ammo == game->player->ammo)
		return ;
	text = ft_strformat("Ammo: %i", game->player->ammo);
	set_elem_text_str(
		get_gui_child(game->ui, "hudInfoAmmo"), text);
	ft_strdel(&text);
	set_elem_redraw(get_gui_child(game->ui, "hudInfo"));
	prev_ammo = game->player->ammo;
}

static void		keys(t_game *game)
{
	static t_uint32 prev_keys = -1;
	char			*text;

	if (prev_keys == game->player->keys)
		return ;
	text = ft_strformat("Keys: %i", game->player->keys);
	set_elem_text_str(
		get_gui_child(game->ui, "hudInfoKeys"), text);
	ft_strdel(&text);
	set_elem_redraw(get_gui_child(game->ui, "hudInfo"));
	prev_keys = game->player->keys;
}

void			loop_game_gui(t_game *game)
{
	health(game);
	ammo(game);
	keys(game);
	set_elem_redraw(get_gui_child(game->ui, "gameView"));
}
