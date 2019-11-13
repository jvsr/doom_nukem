/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:24:25 by pholster       #+#    #+#                */
/*   Updated: 2019/11/13 11:13:56 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_video.h>

#include "game.h"
#include "init.h"
#include "audio.h"
#include "sdl_thread.h"

int	main(int argc, char **argv, char **envp)
{
	t_game 		*game;
	t_bool 		isloaded;
	SDL_Thread *thread;

	isloaded = FALSE;
	game = init();
	thread = sdl_new_thread("loader", loader, 2, game, &isloaded);
	splash(game, &isloaded, "splash/splash");
	loop(game);
	return (0);
}
