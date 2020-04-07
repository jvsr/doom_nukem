/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_convert.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/01 12:20:53 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/07 12:28:31 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_list.h"

#include "error.h"
#include "rinfo.h"
#include "renderer.h"
#include "textures.h"
#include "map_editor.h"

static void fill_wall(t_wall *cur_w, t_editor_wall *e_w)
{
	cur_w->corner_0 = e_w->corner_0;
	cur_w->corner_1 = e_w->corner_1;
	cur_w->is_portal = e_w->is_portal;
	cur_w->is_window = e_w->is_window;
	cur_w->is_door = e_w->is_door;
	cur_w->texture = single_init(TEXTURE_BRICK_WALL, NULL);
	cur_w->win_tex = single_init(TEXTURE_GLASS, NULL);
	cur_w->decals = NULL;
}

static void	add_walls(t_sector *headS, t_sector *map_s, t_editor_sector *cur_s)
{
	size_t i;
	t_list *tmp;
	t_editor_wall *cur_w;

	map_s->wall_count = ft_lstlen(cur_s->walls);
	map_s->walls = ft_memalloc(sizeof(t_wall) * ft_lstlen(cur_s->walls));
	if (map_s->walls == NULL)
		error_msg_errno("Failed to allocate map walls");
	i = 0;
	tmp = cur_s->walls;
	while (i < ft_lstlen(cur_s->walls))
	{
		cur_w = (t_editor_wall*)tmp->content;
		tmp = tmp->next;
		fill_wall(&(map_s->walls[i]), cur_w);
		if (cur_w->is_portal || cur_w->is_window || cur_w->is_door)
		{
			if (cur_s == cur_w->sectors[0])
				map_s->walls[i].window = &headS[cur_w->sectors[0]->index];
			else
				map_s->walls[i].window = &headS[cur_w->sectors[1]->index];
		}
		i++;
	}
} // TODO(jvsr) incongruency between is_hidden_door.

static void	add_objects(t_sector *map_s, t_editor_sector *cur_s)
{
	t_list *obj;
	t_editor_object *cur_obj;
	
	obj = cur_s->objects;
	map_s->object_count = 0;
	while (obj != NULL)
	{
		cur_obj = (t_editor_object*)obj->content;
		map_s->object_count++;
		if (cur_obj->type == O_CHAIR)
			new_chair(&cur_obj->pos, 0, map_s);
		else if (cur_obj->type == O_END)
			new_end(&cur_obj->pos, map_s);
		else if (cur_obj->type == O_ENEMY)
			new_enemy(&cur_obj->pos, map_s);
		else if (cur_obj->type == O_HEALTH_PICKUP)
			new_health_pickup(&cur_obj->pos, map_s);
		else if (cur_obj->type == O_KEY)
			new_key(&cur_obj->pos, map_s);	
		else if (cur_obj->type == O_SPIKE)
			new_spike(&cur_obj->pos, map_s);
		else if (cur_obj->type == O_START)
			new_start(&cur_obj->pos, map_s);
		obj = obj->next;
	}
}

static void	fill_sector_default(t_sector *m_s, t_list **tmp)
{
	*tmp = (*tmp)->next;
	m_s->floor = 0;
	m_s->floor_tex = TEXTURE_QUARTZ;
	m_s->ceil = 40;
	m_s->ceil_tex = TEXTURE_QUARTZ;
	m_s->has_ceiling = TRUE;
	m_s->f_enter = NULL;
	m_s->f_exit = NULL;
	m_s->light_value = 5;
	m_s->has_slope = FALSE;
	m_s->angle = 0;
	m_s->swall = NULL;
}

t_map	*map_editor_convert(t_editor_map *m_edit)
{
	t_map *m;
	size_t i;
	t_list *tmp;
	t_editor_sector *cur_s;

	m = (t_map*)ft_memalloc(sizeof(t_map));
	if (m == NULL)
		error_msg_errno("Failed to allocate map");
	m->has_skybox = m_edit->has_skybox;
	m->skybox = m_edit->skybox;
	m->sector_count = ft_lstlen(m_edit->sectors);
	m->sectors = ft_memalloc(sizeof(t_sector) * ft_lstlen(m_edit->sectors));
	if (m->sectors == NULL)
		error_msg_errno("Failed to allocate map sectors.");
	i = 0;
	tmp = m_edit->sectors;
	while (i < ft_lstlen(m_edit->sectors))
	{
		cur_s = (t_editor_sector*)tmp->content;
		fill_sector_default(&(m->sectors[i]), &tmp);
		add_walls(m->sectors, &(m->sectors[i]), cur_s);
		add_objects(&(m->sectors[i]), cur_s);
		i++;
	}
	return (m);	
}
