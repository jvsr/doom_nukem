/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_del_tqueue.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:41:22 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:41:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

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

void		*sdl_del_tqueue(t_tqueue **queue)
{
	if (queue == NULL || *queue == NULL)
		return (NULL);
	del_tasks((*queue)->first);
	SDL_DestroyMutex((*queue)->lock);
	SDL_DestroyCond((*queue)->cond_empty);
	SDL_DestroyCond((*queue)->cond_not_empty);
	ft_memdel((void**)queue);
	return (NULL);
}
