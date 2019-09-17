/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_elem.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 17:28:28 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/09 14:23:24 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_error.h>

#include "libft/ft_memory.h"

#include "gui.h"
#include "sdl_extra.h"
#include "error.h"

/*
** * Gui internal function
*/

static void	update_pos_dim(t_transform *elem)
{
	SDL_Point	parent_dim;

	if (elem->parent_type == ELEM)
		ft_memcpy(&parent_dim, &elem->parent.elem->abs_dim, sizeof(SDL_Point));
	else
	{
		parent_dim.x = elem->parent.ui->window_surface->w;
		parent_dim.y = elem->parent.ui->window_surface->h;
	}
	elem->abs_pos.x = parent_dim.x * elem->pos.x;
	elem->abs_pos.y = parent_dim.y * elem->pos.y;
	elem->abs_dim.x = parent_dim.x * elem->dim.x;
	elem->abs_dim.y = parent_dim.y * elem->dim.y;
}

static void	reset_surface(t_transform *elem)
{
	if (elem->surface != NULL)
	{
		if (elem->abs_dim.x == elem->surface->w
		&& elem->abs_dim.y == elem->surface->h)
			return ;
		SDL_FreeSurface(elem->surface);
	}
	elem->surface = SDL_CreateRGBSurface(0,
		elem->abs_dim.x,
		elem->abs_dim.y,
		32,
		0x00ff0000,
		0x0000ff00,
		0x000000ff,
		0xff000000);
	if (elem->surface == NULL)
		error_msg(SDL_GetError(), 1);
}

static void	draw_gui_elem(t_transform *elem)
{
	// if (elem->gui_type == TEXT)
	// 	draw_text(elem);
	if (elem->gui_type == IMAGE)
		draw_image(elem);
	// else if (elem->gui_type == BUTTON)
	// 	draw_button(elem);
	else if (elem->gui_type == PANEL)
		draw_panel(elem);
}

void		draw_elem(t_transform *elem)
{
	SDL_Surface	*dst_surface;

	if (elem->redraw == TRUE && elem->show == TRUE)
	{
		update_pos_dim(elem);
		reset_surface(elem);
		draw_gui_elem(elem);
		elem->redraw = FALSE;
	}
	if (elem->parent_type == ELEM)
		dst_surface = elem->parent.elem->surface;
	else
		dst_surface = elem->parent.ui->window_surface;
	sdl_merge_surface(dst_surface, elem->surface, elem->abs_pos);
}
