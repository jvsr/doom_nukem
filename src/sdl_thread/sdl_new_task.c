/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_new_task.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:54:57 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:48:58 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "sdl_thread.h"
#include "error.h"

/*
** * Thread internal function
*/

static void	set_params(t_task *task, size_t param_count, va_list params)
{
	size_t	i;

	i = 0;
	while (i < param_count)
	{
		task->params[i] = va_arg(params, void *);
		i++;
	}
}

t_task		*sdl_new_task(void (*f)(), size_t param_count, va_list params)
{
	t_task	*task;

	task = (t_task *)ft_memalloc(sizeof(t_task));
	if (task == NULL)
		error_msg_errno("Failed to alloc new task");
	task->f = f;
	task->param_count = param_count;
	set_params(task, param_count, params);
	return (task);
}
