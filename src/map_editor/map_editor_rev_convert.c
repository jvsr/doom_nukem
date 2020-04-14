/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_rev_convert.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 13:09:17 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/14 17:09:36 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_list.h"

#include "error.h"
#include "rinfo.h"
#include "map_editor.h"

static void		add_wall(t_editor_map *m_edit, t_wall *w)
{
	t_editor_wall *w_edit;

	w_edit = map_editor_new_wall(m_edit, w->corner_0, w->corner_1);
	if (w_edit == NULL)
		return ;
	w_edit->is_portal = w->is_portal;
	w_edit->is_window = w->is_window;
	w_edit->is_door = w->is_door;
	if (w_edit->is_door && w->texture.left[0] == TEXTURE_BRICK_WALL)
		w_edit->is_hidden_door = TRUE;
	else
		w_edit->is_hidden_door = FALSE;
}

static void		add_object2(t_obj *type, const t_object *o)
{
	if (o->img.left[0] == TEXTURE_SKYBOX_DAY)
		*type = O_SKYBOX_DAY;
	else if (o->img.left[0] == TEXTURE_SKYBOX_DUSK)
		*type = O_SKYBOX_DUSK;
	else if (o->img.left[0] == TEXTURE_SLOPE)
		*type = O_SLOPE;
	else if (o->img.left[0] == TEXTURE_CPLUS)
		*type = O_CPLUS;
	else if (o->img.left[0] == TEXTURE_CMINUS)
		*type = O_CMINUS;
	else if (o->img.left[0] == TEXTURE_FPLUS)
		*type = O_FPLUS;
	else if (o->img.left[0] == TEXTURE_FMINUS)
		*type = O_FMINUS;
}

static void		add_object(t_editor_map *m_edit, t_list *o_lst)
{
	const t_object	*o = (t_object*)o_lst->content;
	t_editor_object *o_edit;
	t_obj			type;

	type = O_INVALID;
	if (o->img.left[0] == TEXTURE_CHAIR_LEFT)
		type = O_CHAIR;
	else if (o->img.left[0] == TEXTURE_SPIKES)
		type = O_SPIKE;
	else if (o->img.left[0] == TEXTURE_START)
		type = O_START;
	else if (o->img.left[0] == TEXTURE_END)
		type = O_END;
	else if (o->img.left[0] == TEXTURE_ENEMY0_F0 + 8)
		type = O_ENEMY;
	else if (o->img.left[0] == TEXTURE_KEYS)
		type = O_KEY;
	else if (o->img.left[0] == TEXTURE_HEALTH_PICKUP)
		type = O_HEALTH_PICKUP;
	else if (o->img.left[0] == TEXUTRE_AMMO)
		type = O_AMMO;
	add_object2(&type, o);
	o_edit = map_editor_new_object(m_edit, type, o->pos);
	if (o_edit == NULL)
		return ;
}

static void		loop_sector(t_editor_map *m_edit, t_sector *s)
{
	size_t			i;
	t_list			*obj;

	i = 0;
	while (i < s->wall_count)
	{
		add_wall(m_edit, &s->walls[i]);
		i++;
	}
	obj = s->objects;
	while (obj != NULL)
	{
		add_object(m_edit, obj);
		obj = obj->next;
	}
}

t_editor_map	*map_editor_rev_convert(t_map *m)
{
	size_t			i;
	t_editor_map	*m_edit;

	m_edit = (t_editor_map*)ft_memalloc(sizeof(t_editor_map));
	if (m_edit == NULL)
		error_msg_errno("Failed to alloc editor map");
	m_edit->has_skybox = m->has_skybox;
	m_edit->skybox = m->skybox;
	i = 0;
	while (i < m->sector_count)
	{
		loop_sector(m_edit, &m->sectors[i]);
		i++;
	}
	return (m_edit);
}
