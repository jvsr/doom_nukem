/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:36:22 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 14:02:45 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

#include "gui.h"
#include "game.h"

static void		polled(t_game *game, SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		game->state = stopped;
	else if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
		game->state = stopped;
	else if (event->type == SDL_MOUSEBUTTONDOWN
	&& event->button.button & SDL_BUTTON_LEFT)
		check_gui_hit(game, (SDL_Point){event->button.x, event->button.y});
}

static void		test_f(t_game *game, t_transform *elem)
{
	set_elem_pos(elem, (t_coord){0, elem->pos.y + 0.05});
	(void)game;
}

void			loop(t_game *game)
{
	SDL_Event	event;

	t_transform *panel;
	panel = new_elem("panel", PANEL);
	set_elem_pos(panel, (t_coord){0.5, 0});
	set_elem_dim(panel, (t_coord){1, 1});
	add_gui_child(&game->ui, panel);

	t_transform *new;
	new = new_elem("Image", IMAGE);
	set_texture_color(&new->gui_elem.image->color, (SDL_Color){34, 192, 86, 0});
	new->gui_elem.image->draw_method = COLOR;
	set_elem_pos(new, (t_coord){0, 0});
	set_elem_dim(new, (t_coord){1, 0.4});
	add_elem_child(panel, new);
	new->clickable = TRUE;
	new->onclick = test_f;

	while (game->state == running)
	{
		SDL_FillRect(game->surface, NULL, 0);
		while (SDL_PollEvent(&event))
			polled(game, &event);
		draw_gui(&game->ui);
		SDL_UpdateWindowSurface(game->window);
	}
}
