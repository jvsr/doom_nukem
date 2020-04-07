/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   del_child.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/16 11:50:04 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:13:20 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_str.h"

#include "gui_internal.h"

void	del_child(t_transform **children, const char *name)
{
	t_transform	*cur;
	t_transform	*prv;

	prv = NULL;
	cur = *children;
	while (cur != NULL && ft_strequ_nocase(cur->name, name) == FALSE)
	{
		prv = cur;
		cur = cur->next;
	}
	if (cur == NULL)
		return ;
	if (cur == *children)
		*children = cur->next;
	else
		prv->next = cur->next;
	cur->parent_type = PARENT_UNDEFINED;
	del_elem(&cur);
}
