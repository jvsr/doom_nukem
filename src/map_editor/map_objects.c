/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_objects.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 12:28:02 by euan          #+#    #+#                 */
/*   Updated: 2020/04/03 12:59:42 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "map_editor.h"
#include "coord.h"
#include "cmath.h"

static void		finish_obj(t_editor_sector *sec, t_editor_object *obj)
{
	ft_lstaddbck(&sec->objects,
		ft_lstnew(obj, sizeof(t_editor_object)));
	obj->sector = sec;
}

static void		map_obj(t_list *secs, t_editor_object *obj)
{
	t_list			*lst;
	t_editor_sector	*sec;
	int				count;
	t_coord			out;
	t_editor_wall	*ew;

	while (secs)
	{
		sec = secs->content;
		lst = sec->walls;
		count = 0;
		while (lst)
		{
			ew = lst->content;
			if (get_collision(&obj->pos, &(t_coord){cos(90), sin(90)},
				(t_coord[2]){ew->corner_0, ew->corner_1}, &out))
				count++;
			lst = lst->next;
		}
		if (count % 2 == 1)
			return (finish_obj(sec, obj));
		secs = secs->next;
	}
}

void			map_objects(t_list *secs, t_list *objs)
{
	while (objs)
	{
		map_obj(secs, objs->content);
		objs = objs->next;
	}
}
