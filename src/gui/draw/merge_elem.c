/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge_elem.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:48:59 by pholster       #+#    #+#                */
/*   Updated: 2020/02/19 14:48:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"
#include "sdl_extra.h"

/*
** * Gui internal function
*/

void	merge_elem(t_transform *cur)
{
	SDL_Surface	*dst_surface;

	if (cur->show == TRUE)
	{
		if (cur->parent_type == ELEM)
			dst_surface = cur->parent.elem->surface;
		else
			dst_surface = cur->parent.ui->window_surface;
		if (cur->gui_type == TEXT || cur->has_alpha)
			sdl_merge_surface_alpha(dst_surface, cur->surface, cur->rel_pos);
		else
			sdl_merge_surface(dst_surface, cur->surface, cur->rel_pos);
	}
}
