/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_manage_thread_worker.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 15:02:28 by ehollidg       #+#    #+#                */
/*   Updated: 2019/12/01 14:50:43 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include "sdl_thread.h"

/*
** * Thread internal function
*/

int			sdl_manage_thread_worker(void *param)
{
	clock_t		start;
	float		waittime;
	t_pool		*pool;
	t_thread	*self;

	start = 0;
	waittime = 0;
	self = param;
	pool = self->pool;
	while (pool != NULL && pool->terminating == FALSE)
	{
		if (pool->suspended == FALSE && pool->tracktime == TRUE)
			start = clock();
		if (pool->suspended == FALSE && pool->centralised == FALSE)
			self->task = sdl_get_task(pool);
		if (pool->suspended == FALSE && self->task != NULL)
		{
			self->state = ACTIVE;
			sdl_complete_task(pool, self, &waittime);
		}
		if (pool->suspended == FALSE && pool->tracktime == TRUE)
			waittime += (float)(clock() - start) / CLOCKS_PER_SEC;
	}
	return (TRUE);
}
