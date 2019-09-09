/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroypanel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:40:59 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 14:21:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_bool.h"
#include "libft/ft_string.h"

void		destroypanel(t_gui *ui, t_panel *panel,
												const t_bool delchildren)
{
	if (panel->transform.onclick != NULL)
		destroyclick(ui, panel->transform.name);
	if (delchildren == TRUE)
		destroychildren(ui, panel->transform.children, TRUE);
	else if (panel->transform.parent != NULL)
		ft_lstadd(&panel->transform.parent->children,
			panel->transform.children);
	ft_strdel(&panel->transform.name);
	free(panel);
	panel = NULL;
}
