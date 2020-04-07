/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_image_draw_method.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 17:05:26 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:12:48 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"

void	set_elem_image_draw_method(t_transform *elem, t_draw_method draw_method)
{
	t_image	*image;

	if (elem->gui_type == IMAGE)
		image = elem->gui_elem.image;
	else
		image = elem->gui_elem.button->image;
	image->draw_method = draw_method;
	set_elem_redraw(elem);
}
