/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   settransformparent.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:02:33 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 13:54:30 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>

#include "libft/ft_list.h"

#include "gui.h"
#include "error.h"

void		settransformparent(t_transform *child, t_transform *parent)
{
	t_list *new;

	new = ft_lstnew(child, sizeof(child));
	if (new == NULL)
		error_msg(strerror(errno), errno);
	child->parent = parent;
	ft_lstadd(&parent->children, new);
	child->layer = (short)ft_lstlen(parent->children);
}
