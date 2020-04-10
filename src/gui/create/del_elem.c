/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_elem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 15:21:28 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:09:27 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL2/SDL_video.h>

#include "libft/ft_str.h"

#include "gui_internal.h"

static void	del_gui_elem(t_transform *elem)
{
	if (elem->gui_type == TEXT)
		del_text(&elem->gui_elem.text);
	else if (elem->gui_type == IMAGE)
		del_image(&elem->gui_elem.image);
	else if (elem->gui_type == BUTTON)
		del_button(&elem->gui_elem.button);
	else if (elem->gui_type == PANEL)
		del_panel(&elem->gui_elem.panel);
	else if (elem->gui_type == GVIEW)
		del_gview(&elem->gui_elem.gview);
	else if (elem->gui_type == MAP_EDITOR)
		del_map_editor(&elem->gui_elem.map_editor);
}

void		del_elem(t_transform **elem)
{
	if (elem == NULL || *elem == NULL)
		return ;
	if ((*elem)->parent_type != PARENT_UNDEFINED)
		remove_elem_parent(*elem);
	ft_strdel(&(*elem)->name);
	del_gui_elem(*elem);
	if ((*elem)->surface != NULL)
		SDL_FreeSurface((*elem)->surface);
	free(*elem);
	*elem = NULL;
}
