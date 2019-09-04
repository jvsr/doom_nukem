/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:36:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 17:27:03 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "gui.h"

static void		polled(t_game *game, SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		game->state = stopped;
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
		game->state = stopped;
	else if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button
		& SDL_BUTTON_LEFT)
		clickcheck(game);
}

static void		testfunc(t_game *game, t_transform *transform)
{
	(void)game;
	transform->visible = FALSE;
	game->ui.redraw = TRUE;
}

void			loop(t_game *game)
{
	SDL_Event event;
	t_button	*button;

	button = buttoncolournew(&(t_guiinfo){"image", TRUE, (t_coord){0.4, 0.4},
			(t_coord){0.2, 0.2}}, "Hey", &(t_font){ROBOTO, 0.2, (SDL_Color){0, 0, 0, 0}}, 0xFFFFFFFF);
	transformparentset(&button->transform, &game->ui.transform);
	transformaddclick(&game->ui, &button->transform, testfunc);
	game->ui.redraw = TRUE;
	while (game->state == running)
	{
		SDL_FillRect(game->surface, NULL, 0);
		while (SDL_PollEvent(&event))
			polled(game, &event);
		drawgui(game);
		SDL_UpdateWindowSurface(game->window);
	}
	buttondestroy(&game->ui, button, TRUE);
}
