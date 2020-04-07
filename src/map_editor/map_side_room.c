/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_side_room.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 12:33:09 by euan          #+#    #+#                 */
/*   Updated: 2020/04/07 13:20:26 by euan          ########   odam.nl         */
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

static t_list	*get_left_most(t_list **cons, t_editor_wall *wall)
{
	t_angle_data	ret;
	t_list			*i;
	t_coord			vec;
	t_coord			tvec;
	float			angle;

	ret = (t_angle_data){-1, NULL, NULL};
	i = *cons;
	vec = get_wall_vector(wall, (*cons)->content);
	printf("\n Angles : \n");
	while (i && i->content)
	{
		tvec = get_wall_vector(i->content, wall);
		angle = wrap_angle(get_angle_from_vectors(&vec, &tvec));
		printf("Angle %f\n", angle);
		if (angle > ret.ang && angle < 360)
			ret = (t_angle_data){angle, i, i->content};
		i = i->next;
	}
	if (*cons && ret.lst_elem)
		ft_lstunlink(cons, ret.lst_elem);
	printf("Final Angle %f\n", ret.ang);
	return (ret.lst_elem);
}

static t_list	*get_right_most(t_list **cons, t_editor_wall *wall)
{
	t_angle_data	ret;
	t_list			*i;
	t_coord			vec;
	t_coord			tvec;
	float			angle;

	ret = (t_angle_data){361, NULL, NULL};
	i = *cons;
	vec = get_wall_vector(wall, (*cons)->content);
	printf("\n Angles : \n");
	while (i && i->content)
	{
		tvec = get_wall_vector(i->content, wall);
		angle = wrap_angle(get_angle_from_vectors(&vec, &tvec));
		printf("Angle %f\n", angle);
		if (angle < ret.ang && angle > 0)
			ret = (t_angle_data){angle, i, i->content};
		i = i->next;
	}
	if (*cons && ret.lst_elem)
		ft_lstunlink(cons, ret.lst_elem);
	printf("Final Angle %f\n", ret.ang);
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
	while (cons && cons->content)
	{
		lmost = get_left_most(&cons, ft_lstlast(trail)->content);
		if (lmost == NULL)
			return (NULL);
		else if (lmost->content == first)
			return (lmost);
		else if (ft_lstfind_content(trail, lmost->content, lmost->content_size))
		{
			ft_lstdel(&lmost, NULL);
			ft_lstdel(&cons, NULL);
			return (NULL);
		}
		printf("L: %f, %f, %f, %f\n", ((t_editor_wall*)lmost->content)->corner_0.x,((t_editor_wall*)lmost->content)->corner_0.y,((t_editor_wall*)lmost->content)->corner_1.x,((t_editor_wall*)lmost->content)->corner_1.y);
		printf("Post Cons %zu\n", ft_lstlen(cons));
		dup = ft_lstdup(trail);
		ft_lstaddbck(&dup, ft_lstdup(lmost));
		pos = lft_room(dup, walls, first);
		if (pos != NULL)
		{
			lmost->next = pos;
			ret = lmost;
			ft_lstdel(&cons, NULL);
		}
		else
			ft_lstdel(&lmost, NULL);
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
	while (cons && cons->content)
	{
		rmost = get_right_most(&cons, ft_lstlast(trail)->content);
		if (rmost == NULL)
			return (NULL);
		else if (rmost->content == first)
			return (rmost);
		else if (ft_lstfind_content(trail, rmost->content, rmost->content_size))
		{
			ft_lstdel(&rmost, NULL);
			if (cons)
				ft_lstdel(&cons, NULL);
			return (NULL);
		}
		printf("R: %f, %f, %f, %f\n", ((t_editor_wall*)rmost->content)->corner_0.x,((t_editor_wall*)rmost->content)->corner_0.y,((t_editor_wall*)rmost->content)->corner_1.x,((t_editor_wall*)rmost->content)->corner_1.y);
		printf("Post Cons %zu\n", ft_lstlen(cons));
		dup = ft_lstdup(trail);
		ft_lstaddbck(&dup, ft_lstdup(rmost));
		pos = right_room(dup, walls, first);
		if (pos != NULL)
		{
			rmost->next = pos;
			ret = rmost;
			ft_lstdel(&cons, NULL);
		}
		else
			ft_lstdel(&rmost, NULL);
		ft_lstdel(&dup, NULL);
	}
	return (ret);
}
