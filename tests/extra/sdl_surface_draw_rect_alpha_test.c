/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_surface_draw_rect_alpha_test.c                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 18:55:20 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 13:54:42 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <SDL2/SDL.h>

#include "coord.h"
#include "color.h"
#include "game.h"
#include "init.h"
#include "personal.h"
#include "sdl_extra.h"

int	main (void)
{
	SDL_Window *window;                    // Declare a pointer

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"Testing",							// window title
		SDL_WINDOWPOS_CENTERED,           	// initial x position
		SDL_WINDOWPOS_CENTERED,          	// initial y position
		INIT_WIDTH,                             	// width, in pixels
		INIT_HEIGHT,                             	// height, in pixels
		0					               	// flags - see below
	);
	if (window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
		return (1);
	}

	SDL_Surface	*s;
	SDL_Surface	*src1;
	SDL_Surface	*src2;
	SDL_Surface	*src3;
	SDL_Surface	*src4;

	// Creating the surface. 
	s = SDL_GetWindowSurface(window);

	// Filling the surface with red color. 
	SDL_FillRect(s, NULL, SDL_MapRGBA(s->format, 255, 255, 255, 255));

	SDL_Event event;
		double time_spent;
		clock_t start;
		clock_t startall;
		clock_t end;
		clock_t endall;
	while (1)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				exit(0);
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
					exit(0);
				else if (event.key.keysym.sym == SDLK_1)
				{
					src1 = SDL_CreateRGBSurface(0, INIT_WIDTH, INIT_HEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					src2 = SDL_CreateRGBSurface(0, INIT_WIDTH, INIT_HEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					src3 = SDL_CreateRGBSurface(0, INIT_WIDTH, INIT_HEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					src4 = SDL_CreateRGBSurface(0, 160, 90, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					SDL_FillRect(src1, NULL, SDL_MapRGBA(src1->format, 34, 180, 23, 180));
					SDL_FillRect(src2, NULL, SDL_MapRGBA(src2->format, 55, 190, 245, 85));
					SDL_FillRect(src3, NULL, SDL_MapRGBA(src3->format, 0, 0, 0, 130));
					SDL_FillRect(src4, NULL, SDL_MapRGBA(src4->format, 0, 0, 0, 155));
					Time(
						Time(sdl_merge_surface_alpha(src1, src3, (SDL_Point){INIT_WIDTH / 2, 0}), "surMerAlp1");
						Time(sdl_merge_surface_alpha(s, src1, (SDL_Point){0, 0}), "surMerAlp2");
						Time(sdl_merge_surface_alpha(s, src2, (SDL_Point){0, INIT_HEIGHT / 2}), "surMerAlp3");
						Time(sdl_merge_surface_alpha(s, src4, (SDL_Point){INIT_WIDTH / 2 - 80, INIT_HEIGHT / 2 - 45}), "surMerAlp4");
						// time(sdl_draw_surface_rect_alpha(s, (t_color){180, 34, 23, 180}, (SDL_Rect){50, 60, 650, 600}), "surDrawRect1");
						Time(
							Time(sdl_draw_surface_rect_alpha(s, (SDL_Color){0x33, 0x33, 0x33, 0xDD}, (SDL_Rect){50, 50, 160, 60}), "surDrawRect2");
							Time(sdl_draw_surface_rect_alpha(s, (SDL_Color){0x33, 0x33, 0x33, 0xDD}, (SDL_Rect){60, 40, 140, 80}), "surDrawRect3");
							Time(sdl_draw_surface_rect_alpha(s, (SDL_Color){0x99, 0x99, 0x99, 0xDD}, (SDL_Rect){60, 50, 140, 60}), "surDrawRect4");
						, "button creation");	
						Time(sdl_draw_surface_rect_alpha(s, (SDL_Color){0x66, 0x66, 0x66, 0x66}, (SDL_Rect){80, 80, INIT_WIDTH / 2 - 35, INIT_HEIGHT / 2 - 50}), "surDrawRect5");
						// time(sdl_draw_surface_rect_alpha(s, (t_color){180, 34, 23, 180}, (SDL_Rect){50, 60, 650, 600}), "surDrawRect6");
					, "total");
				}
			}
		}
		SDL_UpdateWindowSurface(window);
	}

	// Close and destroy the window
	SDL_DestroyWindow(window);

	// Clean up
	SDL_Quit();
	return 0;
}

/*
gcc \
-o sdl_draw_surface_rect_alpha \
-Iincludes \
-Llibft -lft \
-I`brew --cellar`/../include \
-L`brew --cellar`/../lib -lSDL2 \
src/color/rgba_to_color.c \
src/color/color_to_rgba.c \
src/sdl_extra/sdl_merge_surface_alpha.c \
src/sdl_extra/sdl_draw_surface_rect_alpha.c \
tests/extra/sdl_draw_surface_rect_alpha_test.c
*/