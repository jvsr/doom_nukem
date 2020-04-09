/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_rev_convert.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/06 13:09:17 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 16:44:10 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_list.h"

#include "error.h"
#include "rinfo.h"
#include "map_editor.h"

static void	add_wall(t_editor_map *m_edit, t_wall *w)
{
	t_editor_wall *w_edit;

	w_edit = (t_editor_wall*)ft_memalloc(sizeof(t_editor_wall));
	if (w_edit == NULL)
		error_msg_errno("Failed to alloc editor wall");
	w_edit->corner_0 = w->corner_0;
	w_edit->corner_1 = w->corner_1;
	w_edit->is_portal = w->is_portal;
	w_edit->is_window = w->is_window;
	w_edit->is_hidden_door = FALSE;
	w_edit->is_door = w->is_door;
	ft_lstaddbck(&m_edit->sectors, ft_lstnew(w_edit, sizeof(t_editor_wall)));
}

static void	add_object(t_editor_map *m_edit, t_list *o_lst)
{
	const t_object *o = (t_object*)o_lst->content;
	t_editor_object *o_edit;

	o_edit = (t_editor_object*)ft_memalloc(sizeof(t_editor_object));
	if (o_edit == NULL)
		error_msg_errno("Failed to alloc editor wall");
	o_edit->pos = o->pos;
	if (o->img.left[0] == TEXTURE_CHAIR_LEFT)
		o_edit->type = O_CHAIR;
	else if (o->img.left[0] == TEXTURE_SPIKES)
		o_edit->type = O_SPIKE;
	else if (o->img.left[0] == TEXTURE_START)
		o_edit->type = O_START;
	else if (o->img.left[0] == TEXTURE_END)
		o_edit->type = O_END;
	else if (o->img.left[0] == TEXTURE_ENEMY0_F0 + 8)
		o_edit->type = O_ENEMY;
	else if (o->img.left[0] == TEXTURE_KEYS)
		o_edit->type = O_KEY;
	else if (o->img.left[0] == TEXTURE_HEALTH_PICKUP)
		o_edit->type = O_HEALTH_PICKUP;
	ft_lstaddbck(&m_edit->sectors, ft_lstnew(o_edit, sizeof(t_editor_object)));
}

static void	loop_sector(t_editor_map *m_edit, t_sector *s)
{
	size_t			i;
	t_list			*obj;
	t_editor_sector	*s_edit;

	s_edit = (t_editor_sector*)ft_memalloc(sizeof(t_editor_sector));
	if (s_edit == NULL)
		error_msg_errno("Failed to alloc editor sector");
	ft_lstaddbck(&m_edit->sectors, ft_lstnew(s_edit, sizeof(t_editor_sector)));
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
