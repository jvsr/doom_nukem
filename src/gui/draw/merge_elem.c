/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   merge_elem.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:48:59 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:11:47 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"
#include "sdl_extra.h"

/*
** * Gui internal function
*/

void	merge_elem(t_transform *elem)
{
	SDL_Surface	*dst_surface;

	if (elem->show == FALSE)
		return ;
	if (elem->parent_type == ELEM)
		dst_surface = elem->parent.elem->surface;
	else
		dst_surface = elem->parent.ui->window_surface;
	if (elem->gui_type == TEXT || elem->has_alpha)
		sdl_merge_surface_alpha(dst_surface, elem->surface, elem->rel_pos);
	else
		sdl_merge_surface(dst_surface, elem->surface, elem->rel_pos);
}
