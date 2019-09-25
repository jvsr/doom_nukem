/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_run_task.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:58:08 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:47:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"

/*
** * Thread internal function
*/

t_bool		sdl_run_task(const t_task *task)
{
	void	**params;

	params = (void **)task->params;
	if (task->param_count == 0)
		task->f();
	else if (task->param_count == 1)
		task->f(params[0]);
	else if (task->param_count == 2)
		task->f(params[0], params[1]);
	else if (task->param_count == 3)
		task->f(params[0], params[1], params[2]);
	else
		task->f(params[0], params[1], params[2], params[3]);
	return (TRUE);
}
