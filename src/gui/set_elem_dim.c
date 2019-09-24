/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_elem_dim.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 16:21:04 by pholster       #+#    #+#                */
/*   Updated: 2019/09/16 16:21:04 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "gui.h"
#include "coord.h"

void	set_elem_dim(t_transform *elem, t_coord dim)
{
	ft_memcpy(&elem->dim, &dim, sizeof(t_coord));
	set_elem_redraw(elem);
}
