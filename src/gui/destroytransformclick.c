/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroytransformclick.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/10 14:09:51 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 14:29:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		destroytransformclick(t_gui *ui, t_transform *transform)
{
	t_list *lst;
	t_list *pre;

	lst = ui->onclicks;
	while (lst != NULL
		&& !ft_strequ(((t_transform*)(lst->content))->name, transform->name))
	{
		pre = lst;
		lst = lst->next;
	}
	if (lst == NULL)
		return ;
	pre->next = lst->next;
	lst->next = NULL;
	transform->onclick = NULL;
	ft_lstdelone(&lst, NULL);
}
