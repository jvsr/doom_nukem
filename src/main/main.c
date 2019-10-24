/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:24:25 by pholster       #+#    #+#                */
/*   Updated: 2019/10/24 17:26:59 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "game.h"
#include "init.h"
#include "audio.h"
#include "sdl_thread.h"

int			main(void)
{
	t_game 		*game;
	t_bool 		isloaded;
	SDL_Thread *thread;

	isloaded = FALSE;
	game = init();
	thread = sdl_new_thread("loader", loader, 2, game, &isloaded);
	splash(game, &isloaded, "splash/splash");
	loop(game);
	return (quit(game));
}
