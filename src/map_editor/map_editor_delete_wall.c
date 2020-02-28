/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_delete_wall.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 15:04:41 by pholster       #+#    #+#                */
/*   Updated: 2020/02/12 15:04:41 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "libft/ft_printf.h"

#include "game.h"
#include "rinfo.h"
#include "map_editor.h"

void	map_editor_delete_wall(t_editor_map *editor_map, t_wall *wall)
{
	t_list	*lst;

	lst = ft_lstfind_content(editor_map->walls, wall, sizeof(t_wall));
	if (lst == NULL)
		return ;
	ft_lstunlink(&editor_map->walls, lst);
	ft_lstdelone(&lst, &ft_lstdelmem);
}
