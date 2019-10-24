/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_to_children.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 15:52:19 by pholster       #+#    #+#                */
/*   Updated: 2019/09/24 15:17:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft/ft_str.h"
#include "libft/ft_printf.h"
#include "gui.h"
#include "error.h"

/*
** * Gui internal function
*/

static void	duplicate_error(const char *name)
{
	const char	*msg = ft_strformat("Failed to add '%s'", name);

	error_msg("Elem name already in use", EPERM, msg);
}

static void	check_duplicate(t_transform *cur, const char *name)
{
	while (cur != NULL)
	{
		if (ft_strequ(cur->name, name))
			duplicate_error(name);
		cur = cur->next;
	}
}

void		add_to_children(t_transform **children, t_transform *child)
{
	t_transform	*cur;
	t_transform	*prv;

	prv = NULL;
	cur = *children;
	child->next = NULL;
	while (cur != NULL && child->layer > cur->layer)
	{
		if (ft_strequ(cur->name, child->name))
			duplicate_error(child->name);
		prv = cur;
		cur = cur->next;
	}
	if (cur == NULL && prv != NULL)
	{
		prv->next = child;
		return ;
	}
	check_duplicate(cur, child->name);
	if (prv == NULL)
		*children = child;
	else
		prv->next = child;
	child->next = cur;
}
