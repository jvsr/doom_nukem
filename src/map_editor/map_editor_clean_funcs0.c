/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_clean_funcs0.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 12:36:29 by euan          #+#    #+#                 */
/*   Updated: 2020/04/07 13:40:22 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "map_editor.h"
#include "error.h"

t_list			*get_walls_at_point(t_coord *point,
											t_list *walls, t_editor_wall *cur)
{
	t_editor_wall	*wall;
	t_list			*ret;

	ret = NULL;
	while (walls && walls->content != NULL)
	{
		wall = walls->content;
		if (wall != cur && (ft_memequ(&wall->corner_0, point, sizeof(t_coord))
			|| ft_memequ(&wall->corner_1, point, sizeof(t_coord))))
			ft_lstaddbck(&ret, ft_lstnew(wall, sizeof(t_editor_wall)));
		walls = walls->next;
	}
	return (ret);
}

t_coord			*get_corner(t_editor_wall *wall, t_list *prv)
{
	t_list			*lst;
	t_editor_wall	*sw;

	lst = ft_lstindex(prv, ft_lstlen(prv) - 2);
	sw = lst->content;
	if (ft_memequ(&wall->corner_0, &sw->corner_0, sizeof(t_coord)) ||
		ft_memequ(&wall->corner_0, &sw->corner_1, sizeof(t_coord)))
		return (&wall->corner_1);
	return (&wall->corner_0);
}

static t_bool	check(t_editor_wall *wall, t_editor_wall *cur, t_list *prv)
{
	return (ft_memequ(&cur->corner_0, &wall->corner_0, sizeof(t_coord)) ||
			ft_memequ(&cur->corner_1, &wall->corner_0, sizeof(t_coord)) ||
			ft_lstfind_content(prv, cur, sizeof(t_editor_wall)) != NULL);
}

t_list			*get_walls_at_wall(t_list *prv,
											t_editor_wall *wall, t_list *walls)
{
	t_list			*list;
	t_list			*tmp;
	t_list			*per;

	list = get_walls_at_point(get_corner(wall, prv), walls, wall);
	tmp = list;
	per = NULL;
	while (tmp)
	{
		if (check(wall, tmp->content, prv))
		{
			ft_lstunlink(&list, tmp);
			tmp = per;
		}
		per = tmp;
		if (tmp)
			tmp = tmp->next;
	}
	return (list);
}
