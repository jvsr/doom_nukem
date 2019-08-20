/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tp_addtoque.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 21:13:06 by pholster       #+#    #+#                */
/*   Updated: 2019/08/14 15:49:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "threadpool.h"

t_bool		tp_addtoque(t_pool *pool, t_bool priority, t_task *task)
{
	if (pool == NULL || pool->terminating || task == NULL)
		return (FALSE);
	if (priority == FALSE)
	{
		if (pool->last == NULL)
			pool->que = task;
		else
			pool->last->next = task;
		pool->last = task;
		return (TRUE);
	}
	task->next = pool->que;
	pool->que = task;
	if (pool->last == NULL)
		pool->last = task;
	return (TRUE);
}
