/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_manage_thread.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:49:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include "libft/ft_printf.h"
#include "libft/ft_str.h"

#include "sdl_thread.h"

/*
** * Thread internal function
*/

static t_bool	get_task(t_pool *pool, t_thread *self, t_task **task)
{
	char	state;

	if (pool->suspended)
		return (FALSE);
	state = atomic_exchange(&(pool->state), LOCKED);
	if (state == LOCKED)
		return (FALSE);
	*task = pool->que;
	if (*task != NULL)
	{
		self->state = ACTIVE;
		pool->que = (*task)->next;
		if (*task == pool->que_last)
			pool->que_last = NULL;
	}
	atomic_store(&(pool->state), state);
	return (*task != NULL);
}

static void		print_time(t_thread *self, float runtime, float *waittime,
							void (*f)())
{
	char		*timecolor;
	char		*color;

	color = ft_strformat("\033[38;5;%lum", (self->number % 15) + 1);
	timecolor = "\033[38;5;1m";
	if (runtime > *waittime)
		timecolor = "\033[38;5;2m";
	ft_printf("%spool->thread[%zu]%{} - Function %p = %sWaittime: %.4f : \
Runtime %.4f%{}\n", color, self->number, f, timecolor, *waittime, runtime);
	ft_strdel(&color);
	*waittime = 0;
}

static void		run_task(t_pool *pool, t_thread *self, t_task *task,
							float *waittime)
{
	clock_t		start;
	float		runtime;
	void		(*f)();

	start = 0;
	if (pool->tracktime == TRUE)
		start = clock();
	f = task->f;
	sdl_run_task(task);
	free(task);
	if (pool->tracktime == TRUE)
	{
		runtime = (float)(clock() - start) / CLOCKS_PER_SEC;
		print_time(self, runtime, waittime, f);
	}
	self->state = IDLE;
}

int				sdl_manage_thread(void *param)
{
	clock_t		start;
	float		waittime;
	t_task		*task;
	t_pool		*pool;
	t_thread	*self;

	start = 0;
	task = NULL;
	self = param;
	waittime = 0;
	pool = self->pool;
	while (pool != NULL && pool->terminating == FALSE)
	{
		if (pool->tracktime == TRUE)
			start = clock();
		if (get_task(pool, self, &task) == TRUE)
			run_task(pool, self, task, &waittime);
		else if (pool->tracktime == TRUE)
			waittime += (float)(clock() - start) / CLOCKS_PER_SEC;
	}
	return (TRUE);
}
