/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_complete_ttask.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/09 14:40:34 by pholster       #+#    #+#                */
/*   Updated: 2020/02/09 14:40:34 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"

void	sdl_complete_ttask(t_ttask *task)
{
	if ((task->flags & TFLAG_TASK_NO_DELETE) != 0)
		SDL_CondBroadcast(task->cond_completed);
	else
		sdl_del_ttask(&task);
}
