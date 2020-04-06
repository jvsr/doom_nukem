/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map_editor.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 13:29:55 by ehollidg      #+#    #+#                 */
/*   Updated: 2019/12/04 13:29:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_list.h"
#include "libft/ft_num.h"

#include "map_editor.h"
#include "rinfo.h"
#include "textures.h"
#include "sdl_extra.h"
#include "color.h"
#include "game.h"
#include "gui.h"

static void	get_wall_color(SDL_Color *result, t_editor_wall *wall)
{
	if (wall->is_hidden_door == TRUE)
		hex_to_color(result, EDITOR_HIDDEN_DOOR_COLOR);
	else if (wall->is_door == TRUE)
		hex_to_color(result, EDITOR_DOOR_COLOR);
	else if (wall->is_window == TRUE)
		hex_to_color(result, EDITOR_WINDOW_COLOR);
	else if (wall->is_portal == TRUE)
		hex_to_color(result, EDITOR_PORTAL_COLOR);
	else
		hex_to_color(result, EDITOR_WALL_COLOR);
}

static void	draw_wall(SDL_Surface *dst, t_list *lst, SDL_Point pos)
{
	t_editor_wall	*wall;
	t_line			line;
	SDL_Color		color;
	SDL_Color		default_color;

	hex_to_color(&default_color, EDITOR_WALL_COLOR);
	while (lst != NULL)
	{
		wall = (t_editor_wall*)lst->content;
		line.start.x = wall->corner_0.x - pos.x;
		line.start.y = wall->corner_0.y - pos.y;
		line.end.x = wall->corner_1.x - pos.x;
		line.end.y = wall->corner_1.y - pos.y;
		get_wall_color(&color, wall);
		sdl_draw_surface_line(dst, color, line);
		sdl_draw_surface_circ(dst, default_color, (t_circle){EDITOR_WALL_CORNER_SIZE, line.end});
		sdl_draw_surface_circ(dst, default_color, (t_circle){EDITOR_WALL_CORNER_SIZE, line.start});
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

static void	draw_cursor(SDL_Surface *dst, t_game *game, t_transform *elem,
				SDL_Point mouse_pos)
{
	SDL_Surface			*text;
	SDL_Surface			*scaled;
	SDL_Color			preview_color;
	t_map_editor const	*map_editor = elem->gui_elem.map_editor;

	if (map_editor->selected_object != O_INVALID)
	{
		text = get_texture(game, get_tex_for_obj(map_editor->selected_object));
		scaled = sdl_create_surface_default((SDL_Point){20, 20});
		sdl_merge_surface_alpha_scaled(scaled, text);
		sdl_merge_surface_alpha(dst, scaled, (SDL_Point)
			{mouse_pos.x - (scaled->w / 2), mouse_pos.y - (scaled->h / 2)});
		SDL_FreeSurface(scaled);
		return ;
	}
	map_editor_snap_to_grid(elem, &mouse_pos);
	mouse_pos = (SDL_Point){mouse_pos.x - map_editor->pos.x,
		mouse_pos.y - map_editor->pos.y};
	hex_to_color(&preview_color, EDITOR_PREVIEW_PLACE_COLOR);
	sdl_draw_surface_circ(dst, preview_color, (t_circle){EDITOR_PREVIEW_CIRCLE_SIZE, mouse_pos});
	if (map_editor->show_last_click)
	{
		mouse_pos = map_editor->last_click;
		mouse_pos = (SDL_Point){ map_editor->last_click.x - map_editor->pos.x,
			map_editor->last_click.y - map_editor->pos.y};
		sdl_draw_surface_circ(dst, preview_color, (t_circle){EDITOR_PREVIEW_CIRCLE_SIZE, mouse_pos});
	}
}

void		draw_map_editor(SDL_Surface *dst, t_game *game, t_transform *elem)
{
	SDL_Point		mouse_pos;
	SDL_Color		background_color;
	SDL_Point const	pos = elem->gui_elem.map_editor->pos;

	SDL_GetMouseState(&mouse_pos.x, &mouse_pos.y);
	mouse_pos.x = ft_constrain(mouse_pos.x, 0, elem->abs_dim.x);
	mouse_pos.y = ft_constrain(mouse_pos.y, 0, elem->abs_dim.y);
	hex_to_color(&background_color, EDITOR_BACKGROUND_COLOR);
	sdl_fill_surface_color(dst, background_color);
	draw_grid(dst, pos);
	draw_wall(dst, game->editor_map->walls, pos);
	draw_cursor(dst, game, elem, mouse_pos);
}
