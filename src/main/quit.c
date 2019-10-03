/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quit.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/03 12:49:32 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/03 12:49:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "game.h"
#include "init.h"
#include "audio.h"

int		quit(t_game *game)
{
	SDL_DestroyWindow(game->window);
	Mix_Quit();
	TTF_Quit();
	SDL_Quit();
	exit(0);
	return (0);
}
