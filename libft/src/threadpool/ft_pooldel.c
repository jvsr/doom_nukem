/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pooldel.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:53:48 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:47:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_threadpool.h"
#include "ft_memory.h"
#include <stdlib.h>

static void	delque(t_pool *pool)
{
	t_task	*que;
	t_task	*temp;

	que = pool->que;
	pool->que = NULL;
	while (que != NULL)
	{
		temp = que;
		que = que->next;
		free(temp);
	}
}

void		ft_pooldel(t_pool **pool)
{
	t_thread	*thread;
	size_t		current;

	if (pool == NULL || *pool == NULL)
		return ;
	current = (*pool)->size;
	(*pool)->terminating = TRUE;
	while (current > 0)
	{
		current--;
		thread = (*pool)->threads[current];
		if (thread != NULL)
		{
			pthread_join(thread->thread, NULL);
			free(thread);
		}
	}
	ft_memdel((void **)&((*pool)->threads));
	delque(*pool);
	ft_memdel((void **)pool);
}
