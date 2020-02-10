/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_join_ttask.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:39:56 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:39:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

#include "sdl_thread.h"

void	sdl_join_ttask(t_ttask *task)
{
	if (task == NULL)
		return ;
	SDL_LockMutex(task->lock);
	while (task->completed == FALSE)
		SDL_CondWait(task->cond_completed, task->lock);
	SDL_UnlockMutex(task->lock);
}
