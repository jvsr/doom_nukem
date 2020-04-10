/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   map_editor_new.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 14:37:18 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/02/27 14:37:18 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "error.h"
#include "map_editor.h"

t_editor_map	*map_editor_new(void)
{
	t_editor_map	*new;

	new = ft_memalloc(sizeof(t_editor_map));
	if (new == NULL)
		error_msg_errno("Failed to allocate editor_map");
	return (new);
}
