/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_manage_thread_worker.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 15:02:28 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/01 15:02:28 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include "libft/ft_str.h"
#include "libft/ft_mem.h"

#include "sdl_thread.h"
#include "error.h"

int			sdl_manage_thread_worker(void *param)
{
	clock_t		start;
	float		waittime;
	t_pool		*pool;
	t_thread	*self;

	start = 0;
	self = param;
	waittime = 0;
	pool = self->pool;
	while (pool != NULL && pool->terminating == FALSE)
	{
		if (pool->tracktime == TRUE)
			start = clock();
		if (self->state == ACTIVE)
			sdl_complete_task(pool, self, self->task, &waittime);
		if (pool->tracktime == TRUE)
			waittime += (float)(clock() - start) / CLOCKS_PER_SEC;
	}
	return (TRUE);
}
