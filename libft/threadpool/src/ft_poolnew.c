/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_poolnew.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/08/14 16:16:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "threadpool.h"
#include "libft.h"

static t_pool	*freeret(t_pool **pool)
{
	ft_pooldel(pool);
	return (NULL);
}

static t_thread	*threadnew(t_pool *pool, size_t number)
{
	t_thread	*thread;

	thread = (t_thread *)ft_memalloc(sizeof(t_thread));
	if (thread == NULL)
		return (NULL);
	thread->number = number;
	thread->state = IDLE;
	thread->pool = pool;
	if (pthread_create(&(thread->thread), NULL, &tp_threadmanager, thread) != 0)
	{
		free(thread);
		return (NULL);
	}
	return (thread);
}

t_pool			*ft_poolnew(size_t size, t_bool tracktime)
{
	size_t		current;
	t_pool		*pool;

	if (size <= 0)
		return (NULL);
	pool = (t_pool *)ft_memalloc(sizeof(t_pool));
	if (pool == NULL)
		return (NULL);
	pool->threads = (t_thread **)ft_memalloc(sizeof(t_thread *) * size);
	if (pool->threads == NULL)
		return (freeret(&pool));
	pool->size = size;
	pool->state = ACTIVE;
	pool->suspended = TRUE;
	pool->tracktime = tracktime;
	current = size;
	while (current > 0)
	{
		current--;
		pool->threads[current] = threadnew(pool, current);
		if (pool->threads[current] == NULL)
			freeret(&pool);
	}
	pool->suspended = FALSE;
	return (pool);
}
