/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tp_taskrunfnc.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/25 14:58:08 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:47:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_threadpool.h"

t_bool		tp_taskrunfnc(const t_task *task)
{
	void	**params;

	params = (void **)task->params;
	if (task->param_count == 0)
		task->fnc();
	else if (task->param_count == 1)
		task->fnc(params[0]);
	else if (task->param_count == 2)
		task->fnc(params[0], params[1]);
	else if (task->param_count == 3)
		task->fnc(params[0], params[1], params[2]);
	else
		task->fnc(params[0], params[1], params[2], params[3]);
	return (TRUE);
}
