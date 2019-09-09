/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_color.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 16:19:32 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 15:41:34 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>

#include <criterion/criterion.h>

#include "color.h"

Test(rgba_to_color, white) {
    SDL_Color c;
    SDL_Surface *s;

	s = SDL_CreateRGBSurface(0, 3, 3, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    rgba_to_color(&c, SDL_MapRGBA(s->format, 0xFF, 0xFF, 0xFF, 0xFF));
    cr_assert(c.r == 0xFF);
    cr_assert(c.g == 0xFF);
    cr_assert(c.b == 0xFF);
    cr_assert(c.a == 0xFF);
}

Test(rgba_to_color, black) {
    SDL_Color c;
    SDL_Surface *s;

	s = SDL_CreateRGBSurface(0, 3, 3, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    rgba_to_color(&c, SDL_MapRGBA(s->format, 0x00, 0x00, 0x00, 0x00));
    cr_assert(c.r == 0x00);
    cr_assert(c.g == 0x00);
    cr_assert(c.b == 0x00);
    cr_assert(c.a == 0x00);
}

Test(rgba_to_color, other) {
    SDL_Color c;
    SDL_Surface *s;

	s = SDL_CreateRGBSurface(0, 3, 3, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    rgba_to_color(&c, SDL_MapRGBA(s->format, 0x4A, 0x11, 0xDE, 0xF0));
    cr_assert(c.r == 0x4A);
    cr_assert(c.g == 0x11);
    cr_assert(c.b == 0xDE);
    cr_assert(c.a == 0xF0);
}

Test(color_to_rgba, white) {
    int     res;
    SDL_Color c;
    SDL_Surface *s;

    res = 0;
    c.r = 0xFF;
    c.g = 0xFF;
    c.b = 0xFF;
    c.a = 0xFF;
	s = SDL_CreateRGBSurface(0, 3, 3, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    res = color_to_rgba(c);
    cr_assert(res == SDL_MapRGBA(s->format, 0xFF, 0xFF, 0xFF, 0xFF));
}

Test(color_to_rgba, black) {
    int     res;
    SDL_Color c;
    SDL_Surface *s;

    res = 0;
    c.r = 0x00;
    c.g = 0x00;
    c.b = 0x00;
    c.a = 0x00;
	s = SDL_CreateRGBSurface(0, 3, 3, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    res = color_to_rgba(c);
    cr_assert(res == SDL_MapRGBA(s->format, 0x00, 0x00, 0x00, 0x00));
}

Test(color_to_rgba, other) {
    int     res;
    SDL_Color c;
    SDL_Surface *s;

    res = 0;
    c.r = 0x4A;
    c.g = 0x11;
    c.b = 0xDE;
    c.a = 0xF0;
	s = SDL_CreateRGBSurface(0, 3, 3, 32, 0x00ff0000, 0x0000ff00, 0x000000ff, 0xff000000);
    res = color_to_rgba(c);
    cr_assert(res == SDL_MapRGBA(s->format, 0x4A, 0x11, 0xDE, 0xF0));
}
