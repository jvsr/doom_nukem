/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_remove_last_wall.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/23 17:37:31 by pholster      #+#    #+#                 */
/*   Updated: 2020/01/23 17:37:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"

#include "map_editor.h"

void	map_editor_remove_last_wall(t_editor_map *editor_map)
{
	t_list	*last_lst;

	last_lst = ft_lstlast(editor_map->walls);
	if (last_lst == NULL)
		return ;
	map_editor_del_wall(editor_map, last_lst->content);
}
