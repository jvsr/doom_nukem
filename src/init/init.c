/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:46:04 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/13 18:03:27 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "audio.h"
#include "init.h"
#include "eventstate.h"
#include "parse_map.h"
#include "renderer.h"

void	init_function(t_game *game)
{
	init_audio(game);
	init_gui(game);
	load_textures(game);
	init_main_menu(game);
	init_keymap(game);
	parse_map("map/campaign/doom1.wad", game);
	game->cureventstate->eventstate = splash;
}
