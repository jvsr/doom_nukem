/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_elements.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/19 14:48:11 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:11:58 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "gui_internal.h"
#include "sdl_thread.h"
#include "game.h"

/*
** * Gui internal function
*/

static t_ttask	*update_elem(t_transform *elem, t_game *game)
{
	t_ttask		*new;

	if (elem->parent_type == GUI)
	{
		new = sdl_new_ttask(draw_elem, TFLAG_TASK_NO_DELETE, 2, elem, game);
		sdl_add_tpool_ttask(game->pool, new);
		return (new);
	}
	draw_elem(elem, game);
	return (NULL);
}

static t_ttask	*update_elements(t_transform *elem, t_game *game)
{
	t_ttask		*head;
	t_ttask		*new;

	head = NULL;
	while (elem != NULL)
	{
		if (elem->show == TRUE)
		{
			new = update_elem(elem, game);
			if (new != NULL)
			{
				new->next = head;
				head = new;
			}
		}
		elem = elem->next;
	}
	return (head);
}

void			draw_elements(t_transform *elem, t_game *game)
{
	t_ttask	*tasks;

	tasks = update_elements(elem, game);
	sdl_join_ttask_all(tasks);
	while (elem != NULL)
	{
		merge_elem(elem);
		elem = elem->next;
	}
	sdl_del_ttask_all(&tasks);
}
