/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_poolqueback.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 21:13:06 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:48:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_threadpool.h"
#include "ft_mem.h"
#include <stdlib.h>

static t_bool	freeret(t_pool *pool, t_task *task, t_state state)
{
	free(task);
	atomic_store(&(pool->state), state);
	return (FALSE);
}

t_bool			ft_poolqueback(t_pool *pool, void (*f)(), size_t count, ...)
{
	va_list		params;
	t_state		state;
	t_task		*task;

	if (count > 4 || pool->terminating)
		return (FALSE);
	task = (t_task *)ft_memalloc(sizeof(t_task));
	if (task == NULL)
		return (FALSE);
	state = atomic_exchange(&(pool->state), LOCKED);
	while (state == LOCKED)
		state = atomic_exchange(&(pool->state), LOCKED);
	va_start(params, count);
	tp_tasksetinfo(task, f, count, params);
	va_end(params);
	if (pool->terminating)
		return (freeret(pool, task, state));
	if (tp_addtoque(pool, FALSE, task) == FALSE)
		return (freeret(pool, task, state));
	atomic_store(&(pool->state), state);
	return (TRUE);
}
