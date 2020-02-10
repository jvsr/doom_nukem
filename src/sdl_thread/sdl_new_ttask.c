/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_new_ttask.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:42:14 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:42:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "libft/ft_mem.h"
#include "libft/ft_printf.h"

#include "sdl_thread.h"
#include "error.h"

static void		init_lock_cond(t_ttask *task)
{
	task->lock = SDL_CreateMutex();
	if (task->lock == NULL)
		error_msg_sdl(13, "Failed to alloc task 'lock'");
	task->cond_completed = SDL_CreateCond();
	if (task->cond_completed == NULL)
		error_msg_sdl(13, "Failed to alloc queue 'cond_completed'");
}

static void		set_params(t_ttask *task, va_list parameters)
{
	size_t			i;

	i = 0;
	while (i < task->param_count)
	{
		task->params[i] = va_arg(parameters, void *);
		i++;
	}
}

t_ttask			*sdl_new_ttask(void *(*fnc)(), t_uint64 flags,
							size_t param_count, ...)
{
	va_list			parameters;
	t_ttask			*task;

	if (param_count > MAX_TTASK_PARAMS)
	{
		ft_dprintf(2, "Task param count '%zu' out of range\n", param_count);
		return (NULL);
	}
	task = ft_memalloc(sizeof(t_ttask));
	if (task == NULL)
		error_msg_errno("Failed to alloc task struct");
	task->f = fnc;
	task->flags = flags;
	task->param_count = param_count;
	init_lock_cond(task);
	va_start(parameters, param_count);
	set_params(task, parameters);
	va_end(parameters);
	return (task);
}
