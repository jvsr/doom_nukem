/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   childrendestroy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:11:02 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/04 13:46:05 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		deletegui(t_gui *ui, t_transform *transform,
												const t_bool destroychildren)
{
	if (transform->guitype == BUTTON)
		buttondestroy(ui, (t_button*)transform->guielem, destroychildren);
	else if (transform->guitype == PANEL)
		paneldestroy(ui, (t_panel*)transform->guielem, destroychildren);
	else if (transform->guitype == TEXT)
		textdestroy(ui, (t_text*)transform->guielem, destroychildren);
	else if (transform->guitype == IMAGE)
		imagedestroy(ui, (t_image*)transform->guielem, destroychildren);
}

void		childrendestroy(t_gui *ui, t_list *children,
												const t_bool destroychildren)
{
	t_list *lst;

	if (children == NULL)
		return ;
	while (children != NULL)
	{
		deletegui(ui, (t_transform*)children->content, destroychildren);
		ft_strdel(&((t_transform*)children->content)->name);
		lst = children->next;
		free(children);
		children = lst;
	}
}
