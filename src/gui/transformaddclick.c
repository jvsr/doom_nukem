/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transformaddclick.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 10:40:44 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 14:11:07 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"

void		transformaddclick(t_gui *ui, t_transform *transform,
								void (*onclick)(t_game *, t_transform *))
{
	transform->onclick = onclick;
	if (ui->onclicks == NULL)
		ui->onclicks = ft_lstnew(transform, sizeof(t_transform));
	else
		ft_lstadd(&ui->onclicks,
			ft_lstnew(transform, sizeof(t_transform)));
}
