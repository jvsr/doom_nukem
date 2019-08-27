/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   SDL_SurfaceMerge.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 16:55:21 by jvisser        #+#    #+#                */
/*   Updated: 2019/08/27 19:47:06 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>

#include "coord.h"
#include "color.h"

static void	rgba_to_color(t_color *c, int color)
{
	c->a = (unsigned char)(color >> 24);
	c->r = (unsigned char)(color >> 16);
	c->g = (unsigned char)(color >> 8);
	c->b = (unsigned char)(color);
}

static void	color_to_rgba(int *color, t_color c)
{
	*color = 0;
	*color = (c.a << 24) | *color;
	*color = (c.r << 16) | *color;
	*color = (c.g << 8) | *color;
	*color = (c.b) | *color;
}

static void	merge_pixels(int *dst, int *src)
{
	float	op;
	t_color	cdst;
	t_color	csrc;

	rgba_to_color(&cdst, *dst);
	rgba_to_color(&csrc, *src);
	op = (float)csrc.a / 255.0;
	cdst.a = 0xFF;
	cdst.r = (float)(csrc.r - cdst.r) * op + cdst.r;
	cdst.g = (float)(csrc.g - cdst.g) * op + cdst.g;
	cdst.b = (float)(csrc.b - cdst.b) * op + cdst.b;
	color_to_rgba(dst, cdst);
}

void		SDL_SurfaceMerge(SDL_Surface *dst, SDL_Surface *src, t_coord start)
{
	int	x;
	int	y;

	y = 0;
	while (y < src->h)
	{
		if (start.y + y > dst->h)
			break ;
		else if  (start.y + y < 0)
		{
			y++;
			continue ;
		}
		x = 0;
		while (x < src->w)
		{
			if (start.x + x > dst->w)
				break ;
			else if (start.x + x >= 0)
				merge_pixels((int*)dst->pixels + (((int)start.y + y) * dst->w) + ((int)start.x + x),
							(int*)src->pixels + (y * src->w) + x);
			x++;
		}
		y++;
	}
	printf("end\n");
}

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
        return 1;
    }

    SDL_Surface	*s;
    SDL_Surface	*src;
    SDL_Surface	*src2;
    SDL_Surface	*src3;

	s = SDL_GetWindowSurface(window);
	/* Creating the surface. */

	/* Filling the surface with red color. */
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
					src = SDL_CreateRGBSurface(0, 200, 200, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					src2 = SDL_CreateRGBSurface(0, 200, 200, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					// src3 = SDL_CreateRGBSurface(0, 200, 200, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
					SDL_FillRect(src, NULL, SDL_MapRGBA(src->format, 90, 63, 112, 230));
					SDL_FillRect(src2, NULL, SDL_MapRGBA(src2->format, 230, 190, 245, 30));
					// SDL_FillRect(src3, NULL, SDL_MapRGBA(src2->format, 0, 255, 0, 85));
					SDL_SurfaceMerge(s, src, (t_coord){-50, -50});
					SDL_SurfaceMerge(s, src2, (t_coord){50, 50});
					// SDL_SurfaceMerge(s, src3, (t_coord){150, 50});
					// SDL_BlitSurface(src, NULL, s, NULL);
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
