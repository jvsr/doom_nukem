/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_get_ttask.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:41:55 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:03:13 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"

static void	exract_task(t_tthread *thread, t_tqueue *tasks)
{
	t_tjob	*job;

	job = tasks->first;
	thread->task = job->task;
	tasks->first = job->next;
	sdl_del_tjob(&job, FALSE);
	if (tasks->first == NULL)
		tasks->last = NULL;
	tasks->size--;
	if (tasks->size == 0)
		SDL_CondBroadcast(tasks->cond_empty);
}

void		sdl_get_ttask(t_tthread *thread)
{
	t_tpool		*pool;
	t_tqueue	*tasks;

	pool = thread->pool;
	tasks = pool->tasks;
	SDL_LockMutex(tasks->lock);
	while ((pool->flags & TFLAG_POOL_TERMINATE) == 0 && tasks->size == 0)
		SDL_CondWait(tasks->cond_not_empty, tasks->lock);
	if ((pool->flags & TFLAG_POOL_TERMINATE) == 0)
	{
		thread->running_task = TRUE;
		exract_task(thread, tasks);
	}
	SDL_UnlockMutex(tasks->lock);
}
