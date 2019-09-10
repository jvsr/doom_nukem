/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroypanel.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:40:59 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 11:47:10 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_bool.h"
#include "libft/ft_string.h"

void		destroypanel(t_gui *ui, t_panel **panel,
												const t_bool delchildren)
{
	t_panel *pnl;

	pnl = *panel;
	if (pnl->transform.onclick != NULL)
		destroyclick(ui, pnl->transform.name);
	if (delchildren == TRUE)
		destroychildren(ui, pnl->transform.children, TRUE);
	else if (pnl->transform.parent != NULL)
		ft_lstadd(&pnl->transform.parent->children,
			pnl->transform.children);
	ft_strdel(&pnl->transform.name);
	free(pnl);
	panel = NULL;
}
