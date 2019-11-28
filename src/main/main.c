/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:24:25 by pholster       #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/11/25 17:31:31 by jvisser       ########   odam.nl         */
=======
/*   Updated: 2019/11/13 16:34:37 by jvisser       ########   odam.nl         */
>>>>>>> 902071b0a5c1d877af5268d2c75fc4a7a48c2f63
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_video.h>

#include "game.h"
#include "init.h"
#include "audio.h"
#include "sdl_thread.h"

#include "parse_map.h" //

int	main(int argc, char **argv, char **envp)
{
	t_game	*game;

	(void)argc;
	game = init_prerequisites(argv, envp);
	loop(game);
	return (0);
}
