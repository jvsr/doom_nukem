/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tp_threadmanager.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:49:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_threadpool.h"
#include "ft_printf.h"
#include "ft_str.h"
#include <time.h>

static t_bool	gettask(t_pool *pool, t_thread *self, t_task **task)
{
	char	state;

	if (pool->suspended)
		return (FALSE);
	state = atomic_exchange(&(pool->state), LOCKED);
	if (state == LOCKED)
		return (FALSE);
	*task = (t_task *)pool->que;
	if (*task != NULL)
	{
		self->state = ACTIVE;
		pool->que = (*task)->next;
		if (*task == pool->last)
			pool->last = NULL;
	}
	atomic_store(&(pool->state), state);
	return (*task != NULL);
}

static void		runtask(t_pool *pool, t_thread *self, t_task *task,
	float *waittime)
{
	clock_t		start;
	float		runtime;
	char		*timecolor;
	char		*color;
	void		(*f)();

	start = 0;
	if (pool->tracktime == TRUE)
		start = clock();
	f = task->fnc;
	tp_taskrunfnc(task);
	free(task);
	self->state = IDLE;
	if (pool->tracktime == TRUE)
	{
		runtime = (float)(clock() - start) / CLOCKS_PER_SEC;
		color = ft_strformat("\033[38;5;%lum", (self->number % 15) + 1);
		timecolor = "\033[38;5;1m";
		if (runtime > *waittime)
			timecolor = "\033[38;5;2m";
		ft_printf("%spool->thread[%zu]%{} - Function %p = %sWaittime: %.4f : \
Runtime %.4f%{}\n", color, self->number, f, timecolor, *waittime, runtime);
		ft_strdel(&color);
		*waittime = 0;
	}
}

void			*tp_threadmanager(void *param)
{
	clock_t		start;
	float		waittime;
	t_task		*task;
	t_pool		*pool;
	t_thread	*self;

	start = 0;
	task = NULL;
	self = param;
	pool = self->pool;
	waittime = 0;
	while (pool != NULL && pool->terminating == FALSE)
	{
		if (pool->tracktime == TRUE)
			start = clock();
		if (gettask(pool, self, &task) != FALSE)
			runtask(pool, self, task, &waittime);
		else if (pool->tracktime == TRUE)
			waittime += (float)(clock() - start) / CLOCKS_PER_SEC;
	}
	return (NULL);
}
