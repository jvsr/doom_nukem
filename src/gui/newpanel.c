/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newpanel.c                                         :+:    :+:            */
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
#include "libft/ft_string.h"

#include "gui.h"
#include "error.h"

t_panel		*newpanel(t_guiinfo *guiinfo)
{
	t_panel *panel;

	panel = (t_panel*)ft_memalloc(sizeof(t_panel));
	if (panel == NULL)
		error_msg(strerror(errno), errno);
	ft_memcpy(&panel->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&panel->size, &guiinfo->size, sizeof(t_coord));
	panel->transform.name = ft_strdup(guiinfo->name);
	if (panel->transform.name == NULL)
		error_msg(strerror(errno), errno);
	panel->transform.children = NULL;
	panel->transform.guitype = PANEL;
	panel->transform.guielem = (void*)panel;
	panel->transform.onclick = NULL;
	panel->transform.visible = TRUE;
	panel->transform.layer = 0;
	return (panel);
}
