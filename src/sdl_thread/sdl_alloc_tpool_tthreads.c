/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_alloc_tpool_tthreads.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 17:41:17 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:03:29 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "sdl_thread.h"
#include "error.h"

static void	alloc_threads(t_tpool *pool)
{
	size_t	num;

	num = 0;
	pool->threads = ft_memalloc(sizeof(t_tthread *) * pool->size);
	if (pool->threads == NULL)
		error_msg_errno("Failed to alloc thread array");
	while (num < pool->size)
	{
		pool->threads[num] = sdl_new_tthread(pool, num, &sdl_worker_tthread);
		num++;
	}
}

void		sdl_alloc_tpool_tthreads(t_tpool **pool)
{
	if ((*pool)->alloced == TRUE)
		return ;
	alloc_threads(*pool);
	(*pool)->alloced = TRUE;
}
