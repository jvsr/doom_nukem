/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_add_wall.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:37:31 by pholster       #+#    #+#                */
/*   Updated: 2020/01/23 17:37:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_mem.h"

#include "cmath.h"
#include "rinfo.h"
#include "error.h"
#include "map_editor.h"

/*
** Todo Detect if line is inside other line and prevent placing
*/

static t_bool		check_collision(t_wall *wall, t_wall *other,
						t_coord *intersection)
{
	return (get_line_collision(&(t_bicoord){wall->corner_0, wall->corner_1},
		&(t_bicoord){other->corner_0, other->corner_1}, intersection) != NULL);
}

static t_bool	intersection_on_line(t_wall *wall, t_coord *intersection)
{
	if (ft_memequ(&wall->corner_0, intersection, sizeof(t_coord)) == TRUE)
		return (TRUE);
	if (ft_memequ(&wall->corner_1, intersection, sizeof(t_coord)) == TRUE)
		return (TRUE);
	return (FALSE);
}

static void		add_to_back(t_list **head, t_list *new)
{
	t_wall	*new_wall;
	t_wall	*wall;
	t_list	*lst;
	t_bool	valid;
	t_coord	intersection;

	lst = *head;
	valid = TRUE;
	new_wall = (t_wall*)new->content;
	while (lst != NULL)
	{
		wall = (t_wall*)lst->content;
		if (check_collision(new_wall, wall, &intersection) == TRUE)
			valid = intersection_on_line(new_wall, &intersection);
		if (valid == FALSE || lst->next == NULL)
			break ;
		lst = lst->next;
	}
	if (valid == FALSE)
		ft_lstdel(&new, ft_lstdelmem);
	else if (lst == NULL)
		*head = new;
	else
		lst->next = new;
	return ;
}

void	map_editor_add_wall(t_editor_map *editor_map, t_wall *wall)
{
	t_list	*new;

	new = ft_lstnew((void*)wall, sizeof(t_wall));
	if (new == NULL)
		error_msg_errno("Failed to alloc map editor wall");
	add_to_back(&editor_map->walls, new);
}
