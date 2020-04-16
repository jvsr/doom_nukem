/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_clickable.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:25:15 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:12:53 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_bool.h"

#include "gui.h"

void	set_elem_clickable(t_transform *elem, t_bool clickable)
{
	elem->clickable = clickable;
}
