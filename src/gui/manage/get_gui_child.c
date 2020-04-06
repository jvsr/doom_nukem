/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_gui_child.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/06 11:27:49 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:01 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui.h"

t_transform		*get_gui_child(t_gui *ui, const char *name)
{
	t_transform	*found;
	t_transform	*cur;

	found = NULL;
	cur = ui->children;
	while (cur != NULL)
	{
		if (ft_strequ_nocase(cur->name, name) == TRUE)
			return (cur);
		found = get_elem_child(cur, name);
		if (found != NULL)
			return (found);
		cur = cur->next;
	}
	return (NULL);
}
