/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_panel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:22:33 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/25 12:34:14 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_mem.h"

#include "gui.h"
#include "error.h"

/*
** * Gui internal function
*/

t_panel		*new_panel(void)
{
	t_panel *panel;

	panel = (t_panel *)ft_memalloc(sizeof(t_panel));
	if (panel == NULL)
		error_msg_errno("Failed to alloc panel");
	return (panel);
}
