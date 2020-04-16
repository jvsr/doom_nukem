/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_new_tpool.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dkroeke <dkroeke@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/02 16:46:03 by dkroeke       #+#    #+#                 */
/*   Updated: 2020/04/06 12:03:02 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "sdl_thread.h"
#include "error.h"

static void	alloc_queues(t_tpool *pool)
{
	pool->tasks = sdl_new_tqueue();
	if (pool->tasks == NULL)
		error_msg_errno("Failed to alloc queue struct");
}

t_tpool		*sdl_new_tpool(size_t size, t_uint64 flags)
{
	t_tpool		*pool;

	pool = ft_memalloc(sizeof(t_tpool));
	if (pool == NULL)
		error_msg_errno("Failed to alloc thread pool struct");
	pool->size = size;
	pool->flags = flags;
	alloc_queues(pool);
	if ((pool->flags & TFLAG_POOL_ALLOC_ON_EXEC) == 0)
		sdl_alloc_tpool_tthreads(&pool);
	return (pool);
}
