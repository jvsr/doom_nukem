/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loader.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 17:02:28 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/24 17:26:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "game.h"
#include "renderer.h"

void	loader(t_game *game, t_bool *isloaded)
{
	load_textures(game);
	*isloaded = TRUE;
}
