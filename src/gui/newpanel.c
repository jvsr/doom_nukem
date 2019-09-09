/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   panelnew.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:22:33 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 13:42:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_memory.h"
#include "gui.h"
#include "libft/ft_string.h"

t_panel		*newpanel(t_guiinfo *guiinfo)
{
	t_panel *panel;

	panel = (t_panel*)ft_memalloc(sizeof(t_panel));
	ft_memcpy(&panel->transform.position, &guiinfo->position, sizeof(t_coord));
	ft_memcpy(&panel->size, &guiinfo->size, sizeof(t_coord));
	ft_strcpy(panel->transform.name, guiinfo->name);
	panel->transform.children = NULL;
	panel->transform.guitype = PANEL;
	panel->transform.guielem = (void*)panel;
	panel->transform.onclick = NULL;
	panel->transform.visible = TRUE;
	panel->transform.layer = 0;
	return (panel);
}
