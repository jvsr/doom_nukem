/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transformparentset.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:02:33 by ehollidg       #+#    #+#                */
/*   Updated: 2019/09/06 11:11:50 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui.h"
#include "libft/ft_list.h"

void		transformparentset(t_transform *child, t_transform *parent)
{
	child->parent = parent;
	if (parent->children == NULL)
		parent->children = ft_lstnew(child, sizeof(child));
	else
		ft_lstadd(&parent->children, ft_lstnew(child, sizeof(child)));
	child->layer = (short)ft_lstlen(parent->children);
}
