/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_surface_merge_alpha_test.c                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 18:55:20 by jvisser        #+#    #+#                */
/*   Updated: 2019/08/29 13:35:16 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <SDL2/SDL.h>

#include "coord.h"

void		sdl_surface_merge_alpha(SDL_Surface *dst, SDL_Surface *src, t_pixel start);

int	main (void)
{
	SDL_Window *window;                    // Declare a pointer

	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

	// Create an application window with the following settings:
	window = SDL_CreateWindow(
		"Testing",							// window title
		SDL_WINDOWPOS_CENTERED,           	// initial x position
		SDL_WINDOWPOS_CENTERED,          	// initial y position
		1920,                             	// width, in pixels
		1080,                             	// height, in pixels
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
					src1 = SDL_CreateRGBSurface(0, 1920, 1080, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					src2 = SDL_CreateRGBSurface(0, 1920, 1080, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					src3 = SDL_CreateRGBSurface(0, 1920, 1080, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					src4 = SDL_CreateRGBSurface(0, 160, 90, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					SDL_FillRect(src1, NULL, SDL_MapRGBA(src1->format, 180, 21, 254, 85));
					SDL_FillRect(src2, NULL, SDL_MapRGBA(src2->format, 55, 190, 245, 85));
					SDL_FillRect(src3, NULL, SDL_MapRGBA(src3->format, 0, 0, 0, 130));
					SDL_FillRect(src4, NULL, SDL_MapRGBA(src4->format, 0, 0, 0, 255));
					sdl_surface_merge_alpha(src1, src3, (t_pixel){960, 0});
		// SDL_UpdateWindowSurface(window);
		// SDL_Delay(3000);
		clock_t start = clock();
					sdl_surface_merge_alpha(s, src1, (t_pixel){0, 0});
		clock_t end = clock();
		// SDL_UpdateWindowSurface(window);
		// SDL_Delay(3000);
					sdl_surface_merge_alpha(s, src2, (t_pixel){0, 540});
		// SDL_UpdateWindowSurface(window);
		// SDL_Delay(3000);
					sdl_surface_merge_alpha(s, src4, (t_pixel){880, 495});
		// SDL_UpdateWindowSurface(window);
		// SDL_Delay(3000);
		double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
		printf("Time spent: %f\n", time_spent);
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
gcc -o test_surface_merge_alpha -I../../includes -I`brew --cellar`/../include -L`brew --cellar`/../lib -lSDL2 sdl_surface_merge_alpha.c sdl_surface_merge_alpha_test.c
*/
