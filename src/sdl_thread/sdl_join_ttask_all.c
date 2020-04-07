/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_join_ttask_all.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:39:56 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:03:09 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"

void	sdl_join_ttask_all(t_ttask *task)
{
	while (task != NULL)
	{
		sdl_join_ttask(task);
		task = task->next;
	}
}
