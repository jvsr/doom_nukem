/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_map_editor.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 13:29:55 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/13 14:29:37 by jvisser       ########   odam.nl         */
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

static void	draw_object(SDL_Surface *dst, t_game *game, t_obj obj,
				SDL_Point pos)
{
	SDL_Surface		*text;
	SDL_Surface		*scaled;

	scaled = sdl_create_surface_default((SDL_Point){20, 20});
	text = get_texture(game, get_tex_for_obj(obj));
	sdl_merge_surface_alpha_scaled(scaled, text);
	sdl_merge_surface_alpha(dst, scaled,
		(SDL_Point){pos.x - (scaled->w / 2), pos.y - (scaled->h / 2)});
	SDL_FreeSurface(scaled);
}

static void	draw_objects(SDL_Surface *dst, t_game *game, SDL_Point editor_pos)
{
	t_list			*lst;
	t_editor_object	*object;
	SDL_Point		pos;

	lst = game->editor_map->objects;
	while (lst != NULL)
	{
		object = (t_editor_object*)lst->content;
		pos.x = object->pos.x - editor_pos.x;
		pos.y = object->pos.y - editor_pos.y;
		draw_object(dst, game, object->type, pos);
		lst = lst->next;
	}
}

static void	draw_grid(SDL_Surface *dst, SDL_Point editor_pos)
{
	int			x;
	int			y;
	SDL_Color	color;

	x = (EDITOR_GRID_START_OFFSET - editor_pos.x) % EDITOR_GRID_STEP;
	y = (EDITOR_GRID_START_OFFSET - editor_pos.y) % EDITOR_GRID_STEP;
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
	SDL_Color			preview_color;
	t_map_editor const	*map_editor = elem->gui_elem.map_editor;

	if (map_editor->selected_object != O_INVALID)
	{
		draw_object(dst, game, map_editor->selected_object, mouse_pos);
		return ;
	}
	map_editor_snap_to_grid(elem, &mouse_pos);
	mouse_pos = (SDL_Point){mouse_pos.x - map_editor->pos.x,
		mouse_pos.y - map_editor->pos.y};
	hex_to_color(&preview_color, EDITOR_PREVIEW_PLACE_COLOR);
	sdl_draw_surface_circ(dst, preview_color,
						(t_circle){EDITOR_PREVIEW_CIRCLE_SIZE, mouse_pos});
	if (map_editor->show_last_click)
	{
		mouse_pos = map_editor->last_click;
		mouse_pos = (SDL_Point){map_editor->last_click.x - map_editor->pos.x,
			map_editor->last_click.y - map_editor->pos.y};
		sdl_draw_surface_circ(dst, preview_color,
							(t_circle){EDITOR_PREVIEW_CIRCLE_SIZE, mouse_pos});
	}
}

void		draw_map_editor(SDL_Surface *dst, t_game *game, t_transform *elem)
{
	SDL_Point		mouse_pos;
	SDL_Color		background_color;
	SDL_Point const	editor_pos = elem->gui_elem.map_editor->pos;

	SDL_GetMouseState(&mouse_pos.x, &mouse_pos.y);
	mouse_pos.x = ft_constrain(mouse_pos.x, 0, elem->abs_dim.x);
	mouse_pos.y = ft_constrain(mouse_pos.y, 0, elem->abs_dim.y);
	hex_to_color(&background_color, EDITOR_BACKGROUND_COLOR);
	sdl_fill_surface_color(dst, background_color);
	draw_grid(dst, editor_pos);
	if (game->editor_map == NULL)
		return ;
	draw_objects(dst, game, editor_pos);
	draw_walls(dst, game->editor_map->walls, editor_pos);
	draw_cursor(dst, game, elem, mouse_pos);
}
