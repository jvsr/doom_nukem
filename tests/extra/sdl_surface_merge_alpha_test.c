/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_surface_merge_alpha_test.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 18:55:20 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 13:52:50 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <SDL2/SDL.h>

#include "coord.h"
#include "game.h"
#include "test.h"

void		sdl_merge_surface_alpha(SDL_Surface *dst, SDL_Surface *src, t_pixel start);

int	main (void)
{
	SDL_Window *window;                    // Declare a pointer

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"Testing",							// window title
		SDL_WINDOWPOS_CENTERED,           	// initial x position
		SDL_WINDOWPOS_CENTERED,          	// initial y position
		INITWIDTH,                             	// width, in pixels
		INITHEIGHT,                             	// height, in pixels
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
					src1 = SDL_CreateRGBSurface(0, INITWIDTH, INITHEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					src2 = SDL_CreateRGBSurface(0, INITWIDTH, INITHEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					src3 = SDL_CreateRGBSurface(0, INITWIDTH, INITHEIGHT, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					src4 = SDL_CreateRGBSurface(0, 160, 90, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					SDL_FillRect(src1, NULL, SDL_MapRGBA(src1->format, 180, 21, 254, 85));
					SDL_FillRect(src2, NULL, SDL_MapRGBA(src2->format, 55, 190, 245, 85));
					SDL_FillRect(src3, NULL, SDL_MapRGBA(src3->format, 0, 0, 0, 130));
					SDL_FillRect(src4, NULL, SDL_MapRGBA(src4->format, 0, 0, 0, 155));
					time(
						time(sdl_merge_surface_alpha(src1, src3, (t_pixel){INITWIDTH / 2, 0}), "surMerAlp1");
						time(sdl_merge_surface_alpha(s, src1, (t_pixel){0, 0}), "surMerAlp2");
						time(sdl_merge_surface_alpha(s, src2, (t_pixel){0, INITHEIGHT / 2}), "surMerAlp3");
						time(sdl_merge_surface_alpha(s, src4, (t_pixel){INITWIDTH / 2 - 80, INITHEIGHT / 2 - 45}), "surMerAlp4");
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
-o test_surface_merge_alpha \
-Iincludes \
-Llibft -lft \
-I`brew --cellar`/../include \
-L`brew --cellar`/../lib -lSDL2 \
src/sdl_extra/sdl_merge_surface_alpha.c \
src/sdl_extra/sdl_merge_surface_alpha_test.c \
src/color/color_to_rgba.c \
src/color/rgba_to_color.c
*/
