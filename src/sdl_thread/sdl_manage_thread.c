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

int				sdl_manage_thread(void *param)
{
	clock_t		start;
	float		waittime;
	t_pool		*pool;
	t_thread	*self;

	start = 0;
	self = param;
	waittime = 0;
	pool = self->pool;
	self->task = NULL;
	while (pool != NULL && pool->terminating == FALSE)
	{
		if (pool->tracktime == TRUE)
			start = clock();
		if (get_task(pool, self, &(self->task)) == TRUE)
			sdl_complete_task(pool, self, self->task, &waittime);
		else if (pool->tracktime == TRUE)
			waittime += (float)(clock() - start) / CLOCKS_PER_SEC;
	}
	return (TRUE);
}
