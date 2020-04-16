/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_connectors.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: euan <euan@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/03 13:11:28 by euan          #+#    #+#                 */
/*   Updated: 2020/04/03 13:11:53 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_list.h"
#include "map_editor.h"

t_list			*get_connectors(t_list *walls)
{
	t_list			*lst;
	t_editor_wall	*ewall;

	lst = NULL;
	while (walls != NULL)
	{
		ewall = walls->content;
		if (ewall->is_door || ewall->is_hidden_door || ewall->is_portal
			|| ewall->is_window)
			ft_lstaddbck(&lst, ft_lstnew(ewall, sizeof(t_editor_wall)));
		walls = walls->next;
	}
	return (lst);
}
