/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paneldestroy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:40:59 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/29 12:13:11 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_bool.h"

void		paneldestroy(t_panel *panel, const t_bool destroychildren)
{
	if (destroychildren == TRUE)
		childrendestroy(panel->transform.children, TRUE);
	else if (panel->transform.parent != NULL)
		ft_lstadd(&panel->transform.parent->children,
			panel->transform.children);
	free(panel);
	panel = NULL;
}
