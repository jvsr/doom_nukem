/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_map_editor.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 17:37:55 by ehollidg      #+#    #+#                 */
/*   Updated: 2019/12/03 17:37:55 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_mem.h"

#include "gui.h"
#include "types.h"
#include "error.h"

t_map_editor		*new_map_editor(void)
{
	t_map_editor *map_editor;

	map_editor = (t_map_editor *)ft_memalloc(sizeof(t_map_editor));
	if (map_editor == NULL)
		error_msg_errno("Failed to alloc map_editor");
	map_editor->selected_object = O_INVALID;
	return (map_editor);
}
