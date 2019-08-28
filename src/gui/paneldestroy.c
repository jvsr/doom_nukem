/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paneldestroy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:40:59 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/28 17:43:50 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"

void		paneldestroy(t_panel *panel)
{
	ft_lstdel(&panel->transform.children, NULL);
	free(panel);
	panel = NULL;
}
