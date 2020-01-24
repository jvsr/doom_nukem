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
#include "libft/ft_list.h"

#include "map_editor.h"
#include "rinfo.h"
#include "sdl_extra.h"
#include "color.h"
#include "game.h"
#include "gui.h"

static void	draw_wall(SDL_Surface *dst, t_list *lst, SDL_Point pos)
{
	t_wall		*wall;
	t_line		line;
	SDL_Color	line_color;

	hex_to_color(&line_color, EDITOR_LINE_COLOR);
	while (lst != NULL)
	{
		wall = (t_wall*)lst->content;
		line.start.x = wall->corner_0.x - pos.x;
		line.start.y = wall->corner_0.y - pos.y;
		line.end.x = wall->corner_1.x - pos.x;
		line.end.y = wall->corner_1.y - pos.y;
		sdl_draw_surface_line(dst, line_color, line);
		lst = lst->next;
	}
}

static void	draw_grid(SDL_Surface *dst, SDL_Point pos)
{
	int			x;
	int			y;
	SDL_Color	color;

	x = (EDITOR_GRID_START_OFFSET - pos.x) % EDITOR_GRID_STEP;
	y = (EDITOR_GRID_START_OFFSET - pos.y) % EDITOR_GRID_STEP;
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
	SDL_Color		background_color;
	SDL_Point const	pos = elem->gui_elem.map_editor->pos;

	(void)game;
	hex_to_color(&background_color, EDITOR_BACKGROUND_COLOR);
	sdl_fill_surface_color(dst, background_color);
	draw_grid(dst, pos);
	draw_wall(dst, elem->gui_elem.map_editor->wall, pos);
}
