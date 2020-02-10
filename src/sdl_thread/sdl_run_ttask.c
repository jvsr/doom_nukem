/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_run_ttask.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:42:06 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:42:06 by pholster      ########   odam.nl         */
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
	if (param_count == 0)
		task->f();
	else if (param_count == 1)
		task->f(param[0]);
	else if (param_count == 2)
		task->f(param[0], param[1]);
	else if (param_count == 3)
		task->f(param[0], param[1], param[2]);
	else if (param_count == 4)
		task->f(param[0], param[1], param[2], param[3]);
	task->completed = TRUE;
}
