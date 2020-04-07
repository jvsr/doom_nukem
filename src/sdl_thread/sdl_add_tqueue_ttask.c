/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_add_tqueue_ttask.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:42:21 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:03:31 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"

static void	add_job_front(t_tqueue *queue, t_tjob *job)
{
	job->next = queue->first;
	queue->first = job;
	if (queue->last == NULL)
		queue->last = job;
}

static void	add_job_back(t_tqueue *queue, t_tjob *job)
{
	job->next = NULL;
	if (queue->first == NULL)
		queue->first = job;
	else
		queue->last->next = job;
	queue->last = job;
}

static void	add_job(t_tqueue *queue, t_tjob *job)
{
	if ((job->task->flags & TFLAG_TASK_HIGH_PRIOR) != 0)
		add_job_front(queue, job);
	else
		add_job_back(queue, job);
	queue->size++;
	if (queue->size == 1)
		SDL_CondBroadcast(queue->cond_not_empty);
}

t_ttask		*sdl_add_tqueue_ttask(t_tqueue *queue, t_ttask *task)
{
	t_tjob	*job;

	if (task == NULL)
		return (NULL);
	task->completed = FALSE;
	job = sdl_new_tjob(task);
	SDL_LockMutex(queue->lock);
	add_job(queue, job);
	SDL_UnlockMutex(queue->lock);
	return (task);
}
