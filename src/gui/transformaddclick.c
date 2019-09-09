/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transformaddclick.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 10:40:44 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 12:04:34 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"

void		transformaddclick(t_gui *ui, t_transform *transform,
								void (*onclick)(t_game *, t_transform *))
{
	t_list *lst;

	transform->onclick = onclick;
	lst = ft_lstfind_content(ui->onclicks, transform, sizeof(transform));
	if (lst != NULL)
		return ;
	if (ui->onclicks == NULL)
		ui->onclicks = ft_lstnew(transform, sizeof(t_transform));
	else
		ft_lstadd(&ui->onclicks,
			ft_lstnew(transform, sizeof(t_transform)));
}
