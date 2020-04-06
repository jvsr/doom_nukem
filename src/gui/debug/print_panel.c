/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_panel.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/04 17:51:36 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:11:21 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"

#include "gui.h"

static void	put_children(t_transform *child)
{
	while (child != NULL)
	{
		print_elem(child, TRUE);
		child = child->next;
	}
}

void		print_panel(t_panel *panel, t_bool print_children)
{
	t_transform	*cur;

	cur = panel->children;
	ft_printf("%{cyan}Children:%{}\n");
	if (print_children == FALSE)
	{
		while (cur != NULL)
		{
			ft_printf("\t%s\n", cur->name);
			cur = cur->next;
		}
	}
	else
		put_children(cur);
	ft_printf("%{red}End of children%{}\n");
}
