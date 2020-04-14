/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_side_room.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 12:33:09 by euan          #+#    #+#                 */
/*   Updated: 2020/04/14 14:59:01 by euan          ########   odam.nl         */
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

static t_list	*get_most(t_list **cons, t_editor_wall *wall, t_bool is_right)
{
	t_angle_data	ret;
	t_list			*i;
	t_coord			vec;
	t_coord			tvec;
	float			angle;

	ret = (t_angle_data){-400, NULL, NULL};
	i = *cons;
	vec = get_wall_vector(wall, (*cons)->content);
	while (i && i->content)
	{
		tvec = get_wall_vector(i->content, wall);
		angle = get_angle_from_vectors(&vec, &tvec);
		angle *= get_side_vec(&vec, &tvec, (int)is_right);
		if (get_closest(ret.ang, angle))
			ret = (t_angle_data){angle, i, i->content};
		i = i->next;
	}
	if (*cons && ret.lst_elem)
		ft_lstunlink(cons, ret.lst_elem);
	return (ret.lst_elem);
}

static t_bool	handle_ifs(t_list *cons, t_list **most,
					t_editor_wall *first, t_list *trail)
{
	if ((*most) == NULL)
		return (TRUE);
	else if ((*most)->content == first)
	{
		ft_lstdel(&cons, NULL);
		return (TRUE);
	}
	else if (ft_lstfind_content(trail, (*most)->content, (*most)->content_size))
	{
		ft_lstdel(most, NULL);
		ft_lstdel(&cons, NULL);
		*most = NULL;
		return (TRUE);
	}
	return (FALSE);
}

static void		manage_lists(t_list *most,
					t_list **ret, t_list *pos, t_list **cons)
{
	most->next = pos;
	*ret = most;
	ft_lstdel(cons, NULL);
	*cons = NULL;
}

t_list			*get_room(t_list *trail,
					t_list *walls, t_editor_wall *first, t_bool is_right)
{
	t_list	*ret;
	t_list	*cons;
	t_list	*most;
	t_list	*pos;
	t_list	*dup;

	ret = NULL;
	cons = get_cons(trail, walls, first);
	while (cons && cons->content)
	{
		most = get_most(&cons, ft_lstlast(trail)->content, is_right);
		if (handle_ifs(cons, &most, first, trail))
			return (most);
		dup = ft_lstdup(trail);
		ft_lstaddbck(&dup, ft_lstdup(most));
		pos = get_room(dup, walls, first, is_right);
		if (pos != NULL)
			manage_lists(most, &ret, pos, &cons);
		else
			ft_lstdel(&most, NULL);
		ft_lstdel(&dup, NULL);
	}
	ft_lstdel(&cons, NULL);
	return (ret);
}
