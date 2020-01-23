/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map_editor.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 13:29:55 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/04 13:29:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "map_editor.h"
#include "sdl_extra.h"
#include "color.h"
#include "game.h"
#include "gui.h"

static void	ft_drawlinexplus(SDL_Surface *dst, SDL_Point start, SDL_Point end,
							SDL_Color color, float m)
{
	int			dx;
	int			dy;
	int			ystep;

	dx = end.x - start.x;
	dy = end.y - start.y;
	ystep = 1;
	if (dy < 0)
		ystep = -1;
	sdl_draw_surface_rect(dst, color, (SDL_Rect){start.x, start.y, 1, 1});
	while (start.x < end.x)
	{
		m -= dy * ystep;
		start.x += 1;
		if (m < 0)
		{
			start.y += ystep;
			m += dx;
		}
		sdl_draw_surface_rect(dst, color, (SDL_Rect){start.x, start.y, 1, 1});
	}
}

static void	ft_drawlineyplus(SDL_Surface *dst, SDL_Point start, SDL_Point end,
							SDL_Color color, float m)
{
	int			dx;
	int			dy;
	int			xstep;

	dx = end.x - start.x;
	dy = end.y - start.y;
	xstep = 1;
	if (dx < 0)
		xstep = -1;
	sdl_draw_surface_rect(dst, color, (SDL_Rect){start.x, start.y, 1, 1});
	while (start.y < end.y)
	{
		m -= dx * xstep;
		start.y += 1;
		if (m < 0)
		{
			start.x += xstep;
			m += dy;
		}
		sdl_draw_surface_rect(dst, color, (SDL_Rect){start.x, start.y, 1, 1});
	}
}

static void	ft_drawline(SDL_Surface *dst, SDL_Point start, SDL_Point end, SDL_Color color)
{
	float	m;
	int		mode;
	int		dx;
	int		dy;

	dx = end.x - start.x;
	dy = end.y - start.y;
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
		ft_drawline(dst, end, start, color);
		return ;
	}
	if (mode == 1)
		ft_drawlinexplus(dst, start, end, color, m);
	else if (mode == 2)
		ft_drawlineyplus(dst, start, end, color, m);
}

static void	draw_grid(SDL_Surface *dst, t_transform *elem)
{
	int			x;
	int			y;
	SDL_Color	color;

	x = (-1 - elem->gui_elem.map_editor->x_offset) % EDITOR_GRID_STEP;
	y = (-1 - elem->gui_elem.map_editor->y_offset) % EDITOR_GRID_STEP;
	hex_to_color(&color, EDITOR_GRID_COLOR);
	while (x < dst->w)
	{
		ft_drawline(dst, (SDL_Point){x, 0}, (SDL_Point){x, dst->h}, color);
		x += EDITOR_GRID_STEP;
	}
	while (y < dst->h)
	{
		ft_drawline(dst, (SDL_Point){0, y}, (SDL_Point){dst->w, y}, color);
		y += EDITOR_GRID_STEP;
	}
}

void		draw_map_editor(SDL_Surface *dst, t_game *game, t_transform *elem)
{
	t_wall_line	*line;
	t_wall_line	line_copy;
	SDL_Color	background_color;
	SDL_Color	line_color;

	(void)game;
	hex_to_color(&line_color, EDITOR_LINE_COLOR);
	hex_to_color(&background_color, EDITOR_BACKGROUND_COLOR);
	sdl_fill_surface_color(dst, background_color);
	draw_grid(dst, elem);
	line = elem->gui_elem.map_editor->line;
	while (line != NULL)
	{
		ft_memcpy(&line_copy, line, sizeof(t_wall_line));
		line_copy.start.x -= elem->gui_elem.map_editor->x_offset;
		line_copy.start.y -= elem->gui_elem.map_editor->y_offset;
		line_copy.end.x -= elem->gui_elem.map_editor->x_offset;
		line_copy.end.y -= elem->gui_elem.map_editor->y_offset;
		ft_drawline(dst, line_copy.start, line_copy.end, line_color);
		line = line->next;
	}
}
