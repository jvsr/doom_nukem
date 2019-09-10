/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clickdestroy.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 11:04:51 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 13:38:19 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include <stdlib.h>
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		destroyclick(t_gui *ui, char *name)
{
	t_list *lst;
	t_list *prev;

	lst = ui->onclicks;
	prev = NULL;
	while (lst != NULL && !ft_strcmp(((t_transform*)lst->content)->name, name))
	{
		prev = lst;
		lst = lst->next;
	}
	if (lst == NULL)
		return ;
	if (prev != NULL)
		prev->next = lst->next;
	lst->next = NULL;
	ft_lstdelone(&lst, NULL);
}
