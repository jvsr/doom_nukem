/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tp_tasksetinfo.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:54:57 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:48:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_threadpool.h"
#include "ft_memory.h"

t_task	*tp_tasksetinfo(t_task *task, void (*f)(), size_t count, va_list params)
{
	size_t		i;

	i = 0;
	task->fnc = f;
	task->param_count = count;
	task->next = NULL;
	ft_bzero(task->params, sizeof(task->params));
	while (i < count)
	{
		task->params[i] = va_arg(params, void *);
		i++;
	}
	return (task);
}
