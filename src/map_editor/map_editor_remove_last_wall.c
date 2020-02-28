/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_remove_last_wall.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:37:31 by pholster       #+#    #+#                */
/*   Updated: 2020/01/23 17:37:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"

#include "map_editor.h"

void	map_editor_remove_last_wall(t_editor_map *editor_map)
{
	t_list	*lst;
	t_list	*prv;

	prv = NULL;
	lst = editor_map->walls;
	while (lst != NULL && lst->next != NULL)
	{
		prv = lst;
		lst = lst->next;
	}
	if (prv != NULL)
		prv->next = NULL;
	else
		editor_map->walls = NULL;
	ft_lstdel(&lst, &ft_lstdelmem);
}
