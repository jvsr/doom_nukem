/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_show_clickable.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/21 13:03:57 by jvisser        #+#    #+#                */
/*   Updated: 2019/10/21 13:03:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"

#include "gui.h"

void	set_elem_show_clickable(t_transform *elem, t_bool show_click)
{
	elem->show = show_click;
	elem->clickable = show_click;
	set_elem_redraw(elem);
}
