/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_del_ttask_all.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:57:18 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:03:20 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"

static void	del_tasks(t_ttask *task)
{
	t_ttask	*next;

	while (task != NULL)
	{
		next = task->next;
		sdl_del_ttask(&task);
		task = next;
	}
}

void		*sdl_del_ttask_all(t_ttask **task)
{
	if (task == NULL || *task == NULL)
		return (NULL);
	del_tasks(*task);
	*task = NULL;
	return (NULL);
}
