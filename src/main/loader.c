/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 17:02:28 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/13 11:21:10 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "game.h"
#include "init.h"
#include "renderer.h"

void	loader(t_game *game, t_bool *isloaded)
{
	load_textures(game);
	init_main_menu(game);
	*isloaded = TRUE;
}
