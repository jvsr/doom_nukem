/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_run_ttask.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:42:06 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:02:37 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include "sdl_thread.h"

void	sdl_run_ttask(t_ttask *task)
{
	void	**param;
	size_t	param_count;

	param = task->params;
	param_count = task->param_count;
	SDL_LockMutex(task->lock);
	if (param_count == 0)
		task->ret.v_ptr = task->f();
	else if (param_count == 1)
		task->ret.v_ptr = task->f(param[0]);
	else if (param_count == 2)
		task->ret.v_ptr = task->f(param[0], param[1]);
	else if (param_count == 3)
		task->ret.v_ptr = task->f(param[0], param[1], param[2]);
	else if (param_count == 4)
		task->ret.v_ptr = task->f(param[0], param[1], param[2], param[3]);
	SDL_UnlockMutex(task->lock);
}
