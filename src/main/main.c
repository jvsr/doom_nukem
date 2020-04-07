/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 17:24:25 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:49:45 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_video.h>

#include "game.h"
#include "init.h"
#include "audio.h"
#include "sdl_thread.h"

int	main(int argc, char **argv, char **envp)
{
	t_game	*game;

	(void)argc;
	game = init_prerequisites(argv, envp);
	loop(game);
	return (0);
}
