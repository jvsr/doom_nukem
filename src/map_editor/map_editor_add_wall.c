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

#include "gui.h"
#include "rinfo.h"
#include "error.h"
#include "map_editor.h"

void	map_editor_add_wall(t_transform *map_editor_elem, t_wall *wall)
{
	t_list			*new;

	new = ft_lstnew((void*)wall, sizeof(t_wall));
	if (new == NULL)
		error_msg_errno("Failed to alloc map editor wall");
	ft_lstaddbck(&map_editor_elem->gui_elem.map_editor->wall, new);
	set_elem_redraw(map_editor_elem);
}
