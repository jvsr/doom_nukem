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

#include "libft/ft_printf.h"
#include "libft/ft_mem.h"

#include "sdl_thread.h"
#include "error.h"

static t_task	*pass_to_thread(t_task *task, t_pool *pool)
{
	size_t i;

	i = 0;
	while (i < pool->size)
	{
		if (pool->threads[i]->state == IDLE)
		{
			pool->threads[i]->task = task;
			pool->threads[i]->state = ACTIVE;
			return (NULL);
		}
	}
	return (task);
}

static t_task	*collect_task(t_pool *pool)
{
	char	state;
	t_task	*task;

	if (pool->suspended)
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
		if (task == NULL)
			task = collect_task(pool);
		if (task != NULL)
			task = pass_to_thread(task, pool);
	}
	return (TRUE);
}
