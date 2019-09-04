/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paneldestroy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:40:59 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 13:44:49 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_bool.h"
#include "libft/ft_string.h"

void		paneldestroy(t_gui *ui, t_panel *panel,
												const t_bool destroychildren)
{
	if (panel->transform.onclick != NULL)
		clickdestroy(ui, panel->transform.name);
	if (destroychildren == TRUE)
		childrendestroy(ui, panel->transform.children, TRUE);
	else if (panel->transform.parent != NULL)
		ft_lstadd(&panel->transform.parent->children,
			panel->transform.children);
	ft_strdel(&panel->transform.name);
	free(panel);
	panel = NULL;
}
