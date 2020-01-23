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

static void	draw_grid(SDL_Surface *dst, t_transform *elem)
{
	int			x;
	int			y;
	SDL_Color	color;

	x = (-1 - elem->gui_elem.map_editor->pos.x) % EDITOR_GRID_STEP;
	y = (-1 - elem->gui_elem.map_editor->pos.y) % EDITOR_GRID_STEP;
	hex_to_color(&color, EDITOR_GRID_COLOR);
	while (x < dst->w)
	{
		sdl_draw_surface_line(dst, color, (t_line){{x, 0}, {x, dst->h}});
		x += EDITOR_GRID_STEP;
	}
	while (y < dst->h)
	{
		sdl_draw_surface_line(dst, color, (t_line){{0, y}, {dst->w, y}});
		y += EDITOR_GRID_STEP;
	}
}

void		draw_map_editor(SDL_Surface *dst, t_game *game, t_transform *elem)
{
	t_wall_line	*wall_line;
	t_line		line;
	SDL_Color	background_color;
	SDL_Color	line_color;

	(void)game;
	hex_to_color(&line_color, EDITOR_LINE_COLOR);
	hex_to_color(&background_color, EDITOR_BACKGROUND_COLOR);
	sdl_fill_surface_color(dst, background_color);
	draw_grid(dst, elem);
	wall_line = elem->gui_elem.map_editor->line;
	while (wall_line != NULL)
	{
		ft_memcpy(&line, &wall_line->line, sizeof(t_line));
		line.start.x -= elem->gui_elem.map_editor->pos.x;
		line.start.y -= elem->gui_elem.map_editor->pos.y;
		line.end.x -= elem->gui_elem.map_editor->pos.x;
		line.end.y -= elem->gui_elem.map_editor->pos.y;
		sdl_draw_surface_line(dst, line_color, line);
		wall_line = wall_line->next;
	}
}
