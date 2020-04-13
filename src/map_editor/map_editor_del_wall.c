/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_del_wall.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 15:04:41 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/13 14:40:31 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_list.h"

#include "game.h"
#include "map_editor.h"

static t_bool	on_point(t_editor_wall *wall, t_editor_wall *other)
{
	if ((ft_memequ(&wall->corner_0, &other->corner_0, sizeof(t_coord)) ||
		ft_memequ(&wall->corner_0, &other->corner_1, sizeof(t_coord))) &&
		(ft_memequ(&wall->corner_1, &other->corner_0, sizeof(t_coord)) ||
		ft_memequ(&wall->corner_1, &other->corner_1, sizeof(t_coord))))
		return (TRUE);
	return (FALSE);
}

void			map_editor_del_wall(t_editor_map *editor_map,
					t_editor_wall *wall)
{
	t_list	*lst;
	t_list	*next;

	lst = editor_map->walls;
	while (lst != NULL)
	{
		next = lst->next;
		if (on_point(wall, lst->content) == TRUE)
		{
			ft_lstunlink(&editor_map->walls, lst);
			ft_lstdelone(&lst, &ft_lstdelmem);
		}
		lst = next;
	}
}
