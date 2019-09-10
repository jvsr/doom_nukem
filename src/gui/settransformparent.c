/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   settransformparent.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:02:33 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/10 11:55:41 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "error.h"
#include "libft/ft_list.h"

void		settransformparent(t_transform *child, t_transform *parent)
{
	t_list *new;
	new = ft_lstnew(child, sizeof(child));
	if (new == NULL)
		error_msg("Child Elem Could Not Be Allocated", 0);
	child->parent = parent;
	ft_lstadd(&parent->children, new);
	child->layer = (short)ft_lstlen(parent->children);
}
