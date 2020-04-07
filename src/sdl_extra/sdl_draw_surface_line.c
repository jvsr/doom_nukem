/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_draw_surface_line.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 12:34:02 by pholster      #+#    #+#                 */
/*   Updated: 2020/01/23 12:34:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "shape.h"
#include "sdl_extra.h"

static void	put_point(SDL_Surface *dst, SDL_Color color,
						SDL_Point point, size_t size)
{
	SDL_Point const	start = {point.x - (size / 2), point.y - (size / 2)};
	SDL_Point const	end = {point.x + (size / 2), point.y + (size / 2)};

	if (start.x > (dst->w - 1) || start.y > (dst->h - 1)
		|| end.x < 0 || end.x < 0)
		return ;
	sdl_draw_surface_rect(dst, color, (SDL_Rect){start.x, start.y, size, size});
}

static void	draw_line_x_plus(SDL_Surface *dst, SDL_Color color,
								t_line line, float m)
{
	int const	dx = line.end.x - line.start.x;
	int	const	dy = line.end.y - line.start.y;
	int			y_step;

	y_step = 1;
	if (dy < 0)
		y_step = -1;
	put_point(dst, color, line.start, DEFAULT_LINE_SIZE);
	while (line.start.x < line.end.x)
	{
		m -= dy * y_step;
		line.start.x += 1;
		if (m < 0)
		{
			line.start.y += y_step;
			m += dx;
		}
		put_point(dst, color, line.start, DEFAULT_LINE_SIZE);
	}
}

static void	draw_line_y_plus(SDL_Surface *dst, SDL_Color color,
							t_line line, float m)
{
	int const	dx = line.end.x - line.start.x;
	int	const	dy = line.end.y - line.start.y;
	int			x_step;

	x_step = 1;
	if (dx < 0)
		x_step = -1;
	put_point(dst, color, line.start, DEFAULT_LINE_SIZE);
	while (line.start.y < line.end.y)
	{
		m -= dx * x_step;
		line.start.y += 1;
		if (m < 0)
		{
			line.start.x += x_step;
			m += dy;
		}
		put_point(dst, color, line.start, DEFAULT_LINE_SIZE);
	}
}

void		sdl_draw_surface_line(SDL_Surface *dst, SDL_Color color,
									t_line line)
{
	float		m;
	int			mode;
	int const	dx = line.end.x - line.start.x;
	int	const	dy = line.end.y - line.start.y;

	if (abs(dx) > abs(dy))
		mode = 1;
	else
		mode = 2;
	if (mode == 1)
		m = dx;
	else
		m = dy;
	m /= 2;
	if (m < 0)
	{
		sdl_draw_surface_line(dst, color, (t_line){line.end, line.start});
		return ;
	}
	else if (mode == 1)
		draw_line_x_plus(dst, color, line, m);
	else if (mode == 2)
		draw_line_y_plus(dst, color, line, m);
}
