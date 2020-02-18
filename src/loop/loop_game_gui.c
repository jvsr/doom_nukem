/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop_game_gui.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 14:31:35 by euan           #+#    #+#                */
/*   Updated: 2020/02/14 15:11:08 by euan          ########   odam.nl         */
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
		get_gui_child(game->ui, "hudinfohp"), text);
	ft_strdel(&text);
	set_elem_redraw(get_gui_child(game->ui, "hudinfo"));
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
		get_gui_child(game->ui, "hudinfoammo"), text);
	ft_strdel(&text);
	set_elem_redraw(get_gui_child(game->ui, "hudinfo"));
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
		get_gui_child(game->ui, "hudinfokeys"), text);
	ft_strdel(&text);
	set_elem_redraw(get_gui_child(game->ui, "hudinfo"));
	prev_keys = game->player->keys;
}

void			loop_game_gui(t_game *game)
{
	char	*elem_text;
	
	elem_text = ft_strformat("Angle: %.2f Pos: %.2f %.2f Flying : %i",
	game->player->angle, game->player->pos.x, game->player->pos.y,
	game->player->is_flying);
	set_elem_text_str(get_gui_child(game->ui, "angle"), elem_text);
	ft_strdel(&elem_text);
	health(game);
	ammo(game);
	keys(game);
	set_elem_redraw(get_gui_child(game->ui, "gameview"));
}
