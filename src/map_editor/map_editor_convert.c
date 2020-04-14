/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_convert.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/01 12:20:53 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/14 20:08:56 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_list.h"
#include "libft/ft_printf.h"

#include "error.h"
#include "rinfo.h"
#include "renderer.h"
#include "textures.h"
#include "map_editor.h"
#include "table.h"

static t_tablepair_ii const	g_objfuncs[] = {
	{O_CHAIR, new_chair},
	{O_END, new_end},
	{O_ENEMY, new_enemy},
	{O_HEALTH_PICKUP, new_health_pickup},
	{O_KEY, new_key},
	{O_SPIKE, new_spike},
	{O_START, new_start},
	{O_AMMO, new_ammo},
	{O_SKYBOX_DAY, new_skybox_day},
	{O_SKYBOX_DUSK, new_skybox_dusk},
	{O_SLOPE, new_slope},
	{O_CPLUS, new_cplus},
	{O_CMINUS, new_cminus},
	{O_FPLUS, new_fplus},
	{O_FMINUS, new_fminus}
};

static void		add_walls(t_sector *heads, t_sector *map_s,
					t_editor_sector *cur_s)
{
	size_t			i;
	t_list			*tmp;
	t_editor_wall	*cur_w;

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
				map_s->walls[i].window = &heads[cur_w->sectors[1]->index];
			else
				map_s->walls[i].window = &heads[cur_w->sectors[0]->index];
		}
		i++;
	}
}

static void		add_objects(t_sector *map_s, t_editor_sector *cur_s)
{
	size_t const	table_size = sizeof(g_objfuncs) / sizeof(t_tablepair_ii);
	t_list			*obj;
	t_editor_object	*cur_obj;
	t_objcreate		func;

	map_s->object_count = 0;
	obj = cur_s->objects;
	while (obj != NULL)
	{
		cur_obj = (t_editor_object*)obj->content;
		func = find_tablepair_ii_value(g_objfuncs, table_size, cur_obj->type);
		func(&cur_obj->pos, map_s);
		obj = obj->next;
	}
}

static void		fill_sector_default(t_sector *m_s, t_list **tmp)
{
	*tmp = (*tmp)->next;
	m_s->floor = 0;
	m_s->floor_tex = TEXTURE_ROCKS;
	m_s->ceil = 60;
	m_s->ceil_tex = TEXTURE_QUARTZ;
	m_s->has_ceiling = TRUE;
	m_s->f_enter = NULL;
	m_s->f_exit = NULL;
	m_s->light_value = 0.5;
	m_s->has_slope = FALSE;
	m_s->angle = 0;
	m_s->swall = NULL;
}

static t_map	*allocate_map(t_editor_map *m_edit, size_t *i, t_list **tmp)
{
	t_map	*m;

	m = (t_map*)ft_memalloc(sizeof(t_map));
	if (m == NULL)
		error_msg_errno("Failed to allocate map");
	m->has_skybox = m_edit->has_skybox;
	m->skybox = TEXTURE_SKYBOX_DAY;
	m->sector_count = ft_lstlen(m_edit->sectors);
	m->sectors = ft_memalloc(sizeof(t_sector) * ft_lstlen(m_edit->sectors));
	if (m->sectors == NULL)
		error_msg_errno("Failed to allocate map sectors.");
	*i = 0;
	*tmp = m_edit->sectors;
	return (m);
}

t_map			*map_editor_convert(t_editor_map *m_edit)
{
	t_map			*m;
	size_t			i;
	t_list			*tmp;
	t_editor_sector	*cur_s;

	m = allocate_map(m_edit, &i, &tmp);
	while (tmp != NULL)
	{
		((t_editor_sector*)tmp->content)->index = i;
		tmp = tmp->next;
		i++;
	}
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
	convert_clean_doors(m);
	return (m);
}
