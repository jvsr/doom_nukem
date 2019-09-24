/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_panel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:22:33 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:56:14 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_memory.h"

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
		error_msg(strerror(errno), errno, "Failed to alloc panel");
	return (panel);
}
