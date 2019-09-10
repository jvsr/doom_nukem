/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   addtransformclick.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 10:40:44 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 14:00:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_list.h"

#include "gui.h"
#include "error.h"

void		addtransformclick(t_gui *ui, t_transform *transform,
								void (*onclick)(t_game *, t_transform *))
{
	t_list *lst;
	t_list *new;

	transform->onclick = onclick;
	lst = ft_lstfind_content(ui->onclicks, transform, sizeof(transform));
	if (lst != NULL)
		return ;
	new = ft_lstnew(transform, sizeof(t_transform));
	if (new == NULL)
		error_msg(strerror(errno), errno);
	ft_lstadd(&ui->onclicks, new);
}
