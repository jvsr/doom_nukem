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
	t_game		*game;
	t_bool		is_loaded;

	(void)argc;
	is_loaded = FALSE;
	game = init(argv, envp);
	sdl_run_thread("mainmenu", sdl_new_ttask(init_main_menu, 0, 2,
								game, &is_loaded));
	splash(game, &is_loaded, "splash/splash", game->exec_path);
	loop(game);
	quit(0);
}
