/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_run_thread.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 15:25:32 by pholster       #+#    #+#                */
/*   Updated: 2020/02/09 15:25:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"
#include "error.h"

static int	run_task(void *param)
{
	t_ttask *task;

	task = (t_ttask*)param;
	sdl_run_ttask(task);
	sdl_complete_ttask(task);
	return (0);
}

t_ttask		*sdl_run_thread(char const *name, t_ttask *task)
{
	SDL_Thread	*thread;

	if (task == NULL)
		return (NULL);
	thread = SDL_CreateThread(&run_task, name, task);
	if (thread == NULL)
		error_msg_sdl(13, "Failed to alloc run thread");
	SDL_DetachThread(thread);
	return (task);
}
