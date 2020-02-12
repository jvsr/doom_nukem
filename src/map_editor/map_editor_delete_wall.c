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

#include "gui.h"
#include "game.h"
#include "rinfo.h"
#include "map_editor.h"

void	map_editor_delete_wall(t_transform *map_editor_elem, t_wall *wall)
{
	t_list	*lst;

	lst = ft_lstfind_content(map_editor_elem->gui_elem.map_editor->wall,
							wall, sizeof(t_wall));
	if (lst == NULL)
		return ;
	ft_lstunlink(&map_editor_elem->gui_elem.map_editor->wall, lst);
	ft_lstdelone(&lst, &ft_lstdelmem);
}
