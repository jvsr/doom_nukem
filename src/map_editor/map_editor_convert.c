/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_convert.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/01 12:20:53 by jvisser        #+#    #+#                */
/*   Updated: 2020/04/01 16:56:33 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_list.h"

#include "error.h"
#include "rinfo.h"
#include "textures.h"
#include "map_editor.h"

static void	add_walls(t_sector *headS, t_sector *mapS, t_editor_sector *curS)
{
	size_t size = 0;
	t_list *tmp = curS->walls;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	mapS->wall_count = size;
	mapS->walls = ft_memalloc(sizeof(t_wall) * size);

	size_t i = 0;
	tmp = curS->walls;
	while (i < size)
	{
		t_editor_wall *curW = (t_editor_wall*)tmp->content;
		tmp = tmp->next;
		mapS->walls[i].corner_0 = curW->corner_0;
		mapS->walls[i].corner_1 = curW->corner_1;
		mapS->walls[i].is_portal = curW->is_portal;
		mapS->walls[i].is_window = curW->is_window;
		mapS->walls[i].is_door = curW->is_door;
		if (curW->is_portal || curW->is_window || curW->is_door)
		{
			if (curS == curW->sectors[0])
				mapS->walls[i].window = &headS[curW->sectors[0]->index];
			else
				mapS->walls[i].window = &headS[curW->sectors[1]->index];
		}
		// Constants
		mapS->walls[i].texture = single_init(TEXTURE_BRICK_WALL, NULL);
		mapS->walls[i].win_tex = single_init(TEXTURE_GLASS, NULL);
		mapS->walls[i].decals = NULL;
		i++;
	}
	
} // TODO(jvsr) incongruency between is_hidden_door.

t_map	*map_editor_convert(t_editor_map *m_edit)
{
	t_map *m;

	m = (t_map*)ft_memalloc(sizeof(t_map));
	if (m == NULL)
		error_msg_errno("Failed to allocate map");

	m->has_skybox = m_edit->has_skybox;
	m->skybox = m_edit->skybox;

	// Size calculations.
	size_t size = 0;
	t_list *tmp = m_edit->sectors;
	while (tmp != NULL) {
		((t_editor_sector*)tmp->content)->index = size;
		size++;
		tmp = tmp->next;
	}
	m->sector_count = size;
	m->sectors = ft_memalloc(sizeof(t_sector) * size);

	// Parse sectors.
	size_t i = 0;
	tmp = m_edit->sectors;
	while (i < size)
	{
		m->sectors[i].floor = 0;
		m->sectors[i].floor_tex = TEXTURE_QUARTZ;
		m->sectors[i].ceil = 40;
		m->sectors[i].ceil_tex = TEXTURE_QUARTZ;
		m->sectors[i].has_ceiling = TRUE;
		m->sectors[i].f_enter = NULL;
		m->sectors[i].f_exit = NULL;
		m->sectors[i].light_value = 5;
		m->sectors[i].has_slope = FALSE;
		m->sectors[i].angle = 0;
		m->sectors[i].swall = NULL;
		t_editor_sector *curS = (t_editor_sector*)tmp->content;
		tmp = tmp->next;
		add_walls(m->sectors, &(m->sectors[i]), curS);
		i++;
	}
	return (m);	
}
