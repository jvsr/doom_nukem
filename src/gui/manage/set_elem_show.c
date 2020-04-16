/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_show.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:25:15 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:12:34 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"

#include "gui.h"

void	set_elem_show(t_transform *elem, t_bool show)
{
	elem->show = show;
	set_elem_redraw(elem);
}
