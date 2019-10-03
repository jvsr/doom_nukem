/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_que_pool.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 21:13:06 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:47:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"

/*
** * Thread internal function
*/

t_bool		sdl_que_pool(t_pool *pool, t_bool priority, t_task *task)
{
	if (pool->terminating)
		return (FALSE);
	if (priority == FALSE)
	{
		if (pool->que_last == NULL)
			pool->que = task;
		else
			pool->que_last->next = task;
		pool->que_last = task;
		return (TRUE);
	}
	task->next = pool->que;
	pool->que = task;
	if (pool->que_last == NULL)
		pool->que_last = task;
	return (TRUE);
}
