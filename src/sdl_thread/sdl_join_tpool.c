/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_join_tpool.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:39:56 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:39:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"

static t_bool	threads_done(t_tpool *pool)
{
	size_t	i;

	i = 0;
	while (i < pool->size)
	{
		if (pool->threads[i]->running_task == TRUE)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void			sdl_join_tpool(t_tpool *pool)
{
	t_bool	all_done;

	all_done = FALSE;
	if (pool == NULL)
		return ;
	SDL_LockMutex(pool->tasks->lock);
	while (all_done == FALSE)
	{
		while (pool->tasks->size != 0)
			SDL_CondWait(pool->tasks->cond_empty, pool->tasks->lock);
		all_done = threads_done(pool);
	}
	SDL_UnlockMutex(pool->tasks->lock);
}
