/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroychildren.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:11:02 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 11:47:42 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		deletegui(t_gui *ui, t_transform *transform,
												const t_bool delchildren)
{
	if (transform->guitype == BUTTON)
		destroybutton(ui, (t_button**)&transform->guielem, delchildren);
	else if (transform->guitype == PANEL)
		destroypanel(ui, (t_panel**)&transform->guielem, delchildren);
	else if (transform->guitype == TEXT)
		destroytext(ui, (t_text**)&transform->guielem, delchildren);
	else if (transform->guitype == IMAGE)
		destroyimage(ui, (t_image**)&transform->guielem, delchildren);
}

void		destroychildren(t_gui *ui, t_list *children,
												const t_bool delchildren)
{
	t_list *lst;

	if (children == NULL)
		return ;
	while (children != NULL)
	{
		deletegui(ui, (t_transform*)children->content, delchildren);
		ft_strdel(&((t_transform*)children->content)->name);
		lst = children->next;
		free(children);
		children = lst;
	}
}
