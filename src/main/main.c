/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:24:25 by pholster       #+#    #+#                */
/*   Updated: 2019/11/28 14:57:04 by jvisser       ########   odam.nl         */
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
