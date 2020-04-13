/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_clean_funcs0.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 12:36:29 by euan          #+#    #+#                 */
/*   Updated: 2020/04/13 14:40:44 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"
#include "map_editor.h"
#include "error.h"
#include "cmath.h"

t_bool			set_side(t_editor_wall *prev,
					t_editor_wall *cur, t_bool is_right)
{
	if (coordequ(&prev->corner_0, &cur->corner_1) ||
		coordequ(&prev->corner_1, &cur->corner_0))
		return (is_right);
	return (!is_right);
}

t_editor_sector	*get_sector(t_list *walls, t_bool is_right)
{
	t_editor_sector *sec;
	t_editor_wall	*tmp;
	t_list			*prv;

	sec = ft_memalloc(sizeof(t_editor_sector));
	if (sec == NULL)
		error_msg_errno("Unable to allocate sector");
	ft_lstrev(&walls);
	sec->walls = walls;
	prv = NULL;
	while (walls)
	{
		tmp = walls->content;
		if (prv != NULL)
			is_right = set_side(prv->content, walls->content, is_right);
		if (is_right == FALSE)
			tmp->sectors[0] = sec;
		else
			tmp->sectors[1] = sec;
		prv = walls;
		walls = walls->next;
	}
	return (sec);
}

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

t_list			*get_walls_at_wall(t_list *prv,
											t_editor_wall *wall, t_list *walls)
{
	return (get_walls_at_point(get_corner(wall, prv), walls, wall));
}
