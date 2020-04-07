/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_elem_duplicate.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:56:11 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:22 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "libft/ft_str.h"

#include "gui_internal.h"
#include "error.h"

/*
** * Gui internal function
*/

static void	duplicate_error(const char *name)
{
	const char	*msg = ft_strformat("Failed to add '%s'", name);

	error_msg("Elem name already in use", EPERM, msg);
}

static void	check_duplicate(t_transform *child, const char *name)
{
	while (child != NULL)
	{
		if (ft_strequ_nocase(child->name, name) == TRUE)
			duplicate_error(name);
		if (child->gui_type == PANEL)
			check_duplicate(child->gui_elem.panel->children, name);
		child = child->next;
	}
}

void		check_elem_duplicate(t_transform *root_children, t_transform *new)
{
	while (new != NULL)
	{
		check_duplicate(root_children, new->name);
		if (new->gui_type == PANEL)
			check_elem_duplicate(root_children, new->gui_elem.panel->children);
		new = new->next;
	}
}
