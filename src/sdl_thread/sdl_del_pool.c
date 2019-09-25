/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_del_pool.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:53:48 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:47:31 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/ft_mem.h"

#include "sdl_thread.h"

static void	del_que(t_pool *pool)
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

void		sdl_del_pool(t_pool **pool)
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
			SDL_WaitThread(thread->thread, NULL);
			free(thread);
		}
	}
	ft_memdel((void **)&((*pool)->threads));
	del_que(*pool);
	free(*pool);
	*pool = NULL;
}
