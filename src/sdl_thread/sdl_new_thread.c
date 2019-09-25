/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_new_thread.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 13:42:11 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:48:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/ft_mem.h"

#include "sdl_thread.h"
#include "error.h"

static int		run_fnc(void *param)
{
	t_task *task;

	task = (t_task *)param;
	sdl_run_task(task);
	free(task);
	return (TRUE);
}

SDL_Thread		*sdl_new_thread(const char *name, void (*f)(),
								size_t param_count, ...)
{
	va_list		params;
	t_task		*task;
	SDL_Thread	*thread;

	if (param_count > 4)
		return (NULL);
	va_start(params, param_count);
	task = sdl_new_task(f, param_count, params);
	va_end(params);
	thread = SDL_CreateThread(&run_fnc, name, (void *)task);
	if (thread == NULL)
		error_msg_sdl(1, "Failed to alloc new thread");
	return (thread);
}
