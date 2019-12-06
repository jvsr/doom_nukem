/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_manage_thread_central.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 14:37:11 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/01 14:37:11 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"

/*
** * Thread internal function
*/

static t_task	*pass_to_thread(t_task *task, t_pool *pool)
{
	t_thread	*thread;
	size_t		i;

	i = 0;
	while (i < pool->size)
	{
		thread = pool->threads[i];
		if (thread->state == IDLE && thread->task == NULL)
		{
			thread->task = task;
			return (NULL);
		}
		i++;
	}
	return (task);
}

int				sdl_manage_thread_central(void *param)
{
	t_pool		*pool;
	t_task		*task;

	pool = param;
	task = NULL;
	while (pool != NULL && pool->terminating == FALSE)
	{
		if (pool->suspended == FALSE && task == NULL)
			task = sdl_get_task(pool);
		if (pool->suspended == FALSE && task != NULL)
			task = pass_to_thread(task, pool);
	}
	return (TRUE);
}
