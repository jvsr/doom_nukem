/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_fill_wall.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/13 14:54:20 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 18:18:50 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "map_editor.h"
#include "textures.h"
#include "rinfo.h"

void		fill_wall(t_wall *cur_w, t_editor_wall *e_w)
{
	cur_w->corner_0 = e_w->corner_0;
	cur_w->corner_1 = e_w->corner_1;
	cur_w->is_portal = e_w->is_portal;
	cur_w->is_window = e_w->is_window;
	cur_w->is_door = e_w->is_door;
	cur_w->perc = (t_coord){0.2, 0.2};
	if (e_w->is_door && e_w->is_hidden_door == FALSE)
		cur_w->texture = single_init(TEXTURE_DOOR, NULL);
	else
		cur_w->texture = single_init(TEXTURE_BRICK_WALL, NULL);
	cur_w->win_tex = single_init(TEXTURE_GLASS, NULL);
	cur_w->decals = NULL;
}
