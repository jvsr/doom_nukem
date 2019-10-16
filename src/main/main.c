/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:24:25 by pholster       #+#    #+#                */
/*   Updated: 2019/09/25 15:39:48 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_video.h>

#include "game.h"
#include "init.h"
#include "sdl_thread.h"

int	main(void)
{
	t_game *game;
	t_bool isloaded;

	isloaded = FALSE;
	game = init();
	sdl_new_thread("mainmenu", init_main_menu, 2, game, &isloaded);
	// splash(game, &isloaded, "splash/splash");
	loop(game);
	return (quit(game));
}
