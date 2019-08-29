/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   childrendestroy.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:11:02 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/29 11:33:00 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"
#include "libft/ft_string.h"

void		deletegui(t_transform *transform)
{
	if (transform->guitype == BUTTON)
		buttondestroy((t_button*)transform->guielem, TRUE);
	else if (transform->guitype == PANEL)
		paneldestroy((t_panel*)transform->guielem, TRUE);
	else if (transform->guitype == TEXT)
		textdestroy((t_text*)transform->guielem, TRUE);
	else if (transform->guitype == IMAGE)
		imagedestroy((t_image*)transform->guielem, TRUE);
}

void		childrendestroy(t_list *children, const t_bool destroychildren)
{
	t_list *lst;

	if (children == NULL)
		return ;
	while (children != NULL)
	{
		deletegui((t_transform*)children->content);
		ft_strdel(&((t_transform*)children->content)->name);
		lst = children->next;
		free(children);
		children = lst;
	}
}
