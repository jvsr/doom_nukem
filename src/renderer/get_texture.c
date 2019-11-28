/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_texture.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 16:50:37 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/24 17:14:22 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include "types.h"
#include "game.h"

SDL_Surface		*get_texture(t_game *game, t_texture texture)
{
	return (game->textures[texture]);
}
