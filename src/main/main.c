/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:24:25 by pholster       #+#    #+#                */
/*   Updated: 2019/11/12 15:44:16 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_video.h>

#include "game.h"
#include "init.h"
#include "sdl_thread.h"

int	main(int argc, char **argv, char **envp)
{
	SDL_Thread	*init_thread;
	t_game		*game;
	t_bool		is_loaded;

	(void)argc;
	is_loaded = FALSE;
	game = init(argv, envp);
	init_thread = sdl_new_thread("mainmenu", init_main_menu, 2,
								game, &is_loaded);
	SDL_DetachThread(init_thread);
	splash(game, &is_loaded, "splash/splash", game->exec_path);
	loop(game);
	quit(0);
}
