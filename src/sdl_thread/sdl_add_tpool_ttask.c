/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_add_tpool_ttask.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:42:21 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:02:14 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"

t_ttask		*sdl_add_tpool_ttask(t_tpool *pool, t_ttask *task)
{
	if (task == NULL || (pool->flags & TFLAG_POOL_TERMINATE) != 0)
		return (NULL);
	if (pool->alloced == FALSE && (pool->flags & TFLAG_POOL_ALLOC_ON_EXEC) != 0)
		sdl_alloc_tpool_tthreads(&pool);
	return (sdl_add_tqueue_ttask(pool->tasks, task));
}
