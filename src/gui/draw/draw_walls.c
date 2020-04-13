/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_walls.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 14:28:56 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/13 14:29:55 by jvisser       ########   odam.nl         */
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

void		draw_walls(SDL_Surface *dst, t_list *lst, SDL_Point editor_pos)
{
	t_editor_wall	*wall;
	t_line			line;
	SDL_Color		color;
	SDL_Color		default_color;

	hex_to_color(&default_color, EDITOR_WALL_COLOR);
	while (lst != NULL)
	{
		wall = (t_editor_wall*)lst->content;
		line.start.x = wall->corner_0.x - editor_pos.x;
		line.start.y = wall->corner_0.y - editor_pos.y;
		line.end.x = wall->corner_1.x - editor_pos.x;
		line.end.y = wall->corner_1.y - editor_pos.y;
		get_wall_color(&color, wall);
		sdl_draw_surface_line(dst, color, line);
		sdl_draw_surface_circ(dst, default_color,
							(t_circle){EDITOR_WALL_CORNER_SIZE, line.end});
		sdl_draw_surface_circ(dst, default_color,
							(t_circle){EDITOR_WALL_CORNER_SIZE, line.start});
		lst = lst->next;
	}
}
