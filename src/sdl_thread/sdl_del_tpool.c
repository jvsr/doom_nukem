/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_del_tpool.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:41:38 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:03:23 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/ft_mem.h"

#include "sdl_thread.h"

static void	del_threads(t_tpool *pool)
{
	size_t	i;

	i = 0;
	if (pool->threads == NULL)
		return ;
	SDL_LockMutex(pool->tasks->lock);
	SDL_CondBroadcast(pool->tasks->cond_not_empty);
	SDL_UnlockMutex(pool->tasks->lock);
	while (i < pool->size)
	{
		SDL_WaitThread(pool->threads[i]->id, NULL);
		sdl_del_tthread(&pool->threads[i]);
		i++;
	}
	free(pool->threads);
}

void		*sdl_del_tpool(t_tpool **pool)
{
	if (pool == NULL || *pool == NULL)
		return (NULL);
	(*pool)->flags |= TFLAG_POOL_TERMINATE;
	del_threads(*pool);
	sdl_del_tqueue(&(*pool)->tasks);
	ft_memdel((void**)pool);
	return (NULL);
}
