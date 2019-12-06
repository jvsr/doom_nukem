/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_get_task.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/06 13:09:26 by pholster       #+#    #+#                */
/*   Updated: 2019/12/06 13:09:26 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include "sdl_thread.h"

/*
** * Thread internal function
*/

t_task		*sdl_get_task(t_pool *pool)
{
	atomic_char	state;
	t_task		*task;

	if (pool->que == NULL)
		return (NULL);
	state = atomic_exchange(&(pool->state), LOCKED);
	if (state == LOCKED)
		return (NULL);
	task = pool->que;
	if (task != NULL)
	{
		pool->que = task->next;
		if (task == pool->que_last)
			pool->que_last = NULL;
	}
	atomic_store(&(pool->state), state);
	task->next = NULL;
	return (task);
}
