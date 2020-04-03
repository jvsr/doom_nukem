/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_side_room.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 12:33:09 by euan           #+#    #+#                */
/*   Updated: 2020/04/03 12:56:17 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "map_editor.h"
#include "coord.h"
#include "cmath.h"

static t_list	*get_cons(t_list *trail, t_list *walls, t_editor_wall *first)
{
	if (ft_lstlen(trail) == 1)
		return (get_walls_at_point(&first->corner_0, walls, first));
	else
		return (get_walls_at_wall(trail, ft_lstlast(trail)->content, walls));
}

static t_list	*get_left_most(t_list *walls, t_editor_wall *wall)
{
	t_angle_data	ret;
	t_list			*i;
	t_coord			vec;
	t_coord			tvec;
	float			angle;

	ret = (t_angle_data){-1, NULL, NULL};
	i = walls;
	vec = get_wall_vector(wall, walls->content);
	while (i)
	{
		tvec = get_wall_vector(i->content, wall);
		angle = wrap_angle(get_angle_from_vectors(&vec, &tvec));
		if (angle > ret.ang && angle < 360)
			ret = (t_angle_data){angle, i, i->content};
		i = i->next;
	}
	remove_from_list(walls, ret.lst_elem);
	return (ret.lst_elem);
}

static t_list	*get_right_most(t_list *walls, t_editor_wall *wall)
{
	t_angle_data	ret;
	t_list			*i;
	t_coord			vec;
	t_coord			tvec;
	float			angle;

	ret = (t_angle_data){-1, NULL, NULL};
	i = walls;
	vec = get_wall_vector(wall, walls->content);
	while (i)
	{
		tvec = get_wall_vector(i->content, wall);
		angle = wrap_angle(get_angle_from_vectors(&vec, &tvec));
		if (angle < ret.ang && angle > 0)
			ret = (t_angle_data){angle, i, i->content};
		i = i->next;
	}
	remove_from_list(walls, ret.lst_elem);
	return (ret.lst_elem);
}

t_list			*lft_room(t_list *trail, t_list *walls, t_editor_wall *first)
{
	t_list	*ret;
	t_list	*cons;
	t_list	*lmost;
	t_list	*pos;
	t_list	*dup;

	ret = NULL;
	cons = get_cons(trail, walls, first);
	while (cons)
	{
		lmost = get_left_most(walls, ft_lstlast(trail)->content);
		if (lmost->content == first)
			return (lmost);
		dup = ft_lstdup(trail);
		ft_lstaddbck(&dup, ft_lstdup(lmost));
		pos = lft_room(dup, walls, first);
		if (pos != NULL)
		{
			lmost->next = pos;
			ret = lmost;
			ft_lstdel(&cons, NULL);
		}
		ft_lstdel(&dup, NULL);
	}
	return (ret);
}

t_list			*right_room(t_list *trail, t_list *walls, t_editor_wall *first)
{
	t_list	*ret;
	t_list	*cons;
	t_list	*rmost;
	t_list	*pos;
	t_list	*dup;

	ret = NULL;
	cons = get_cons(trail, walls, first);
	while (cons)
	{
		rmost = get_right_most(walls, ft_lstlast(trail)->content);
		if (rmost->content == first)
			return (rmost);
		dup = ft_lstdup(trail);
		ft_lstaddbck(&dup, ft_lstdup(rmost));
		pos = right_room(dup, walls, first);
		if (pos != NULL)
		{
			rmost->next = pos;
			ret = rmost;
			ft_lstdel(&cons, NULL);
		}
		ft_lstdel(&dup, NULL);
	}
	return (ret);
}
