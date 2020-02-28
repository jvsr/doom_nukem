/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_find_object_sector.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 15:34:51 by pholster       #+#    #+#                */
/*   Updated: 2020/02/28 15:34:51 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"

#include "rinfo.h"
#include "map_editor.h"

t_editor_sector	*map_editor_find_object_sector(t_editor_map *editor_map,
					t_object *object)
{
	t_list			*sector_list;
	t_editor_sector	*sector;

	sector_list = editor_map->sectors;
	while (sector_list != NULL)
	{
		sector = (t_editor_sector*)sector_list->content;
		if (ft_lstfind_content(sector->walls, object, sizeof(t_object)) != NULL)
			return (sector);
		sector_list = sector_list->next;
	}
	return (NULL);
}
