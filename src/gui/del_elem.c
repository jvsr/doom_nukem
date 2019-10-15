/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_elem.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 15:21:28 by pholster       #+#    #+#                */
/*   Updated: 2019/09/24 15:16:11 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL2/SDL_video.h>

#include "libft/ft_str.h"

#include "gui.h"

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