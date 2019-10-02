/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_complete_task.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 15:21:23 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/01 15:21:23 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>

#include "libft/ft_printf.h"
#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "sdl_thread.h"
#include "error.h"

static void		print_time(t_thread *self, float runtime, float *waittime,
							void (*f)())
{
	char		*timecolor;
	char		*color;

	color = ft_strformat("\033[38;5;%lum", (self->number % 15) + 1);
	timecolor = "\033[38;5;1m";
	if (runtime > *waittime)
		timecolor = "\033[38;5;2m";
	ft_printf("%spool->thread[%zu]%{} - Function %p = %sWaittime: %.4f : \
Runtime %.4f%{}\n", color, self->number, f, timecolor, *waittime, runtime);
	ft_strdel(&color);
	*waittime = 0;
}

void			sdl_complete_task(t_pool *pool, t_thread *self, t_task *task,
							float *waittime)
{
	clock_t		start;
	float		runtime;
	void		(*f)();

	start = 0;
	if (pool->tracktime == TRUE)
		start = clock();
	f = task->f;
	sdl_run_task(task);
	free(task);
	if (pool->tracktime == TRUE)
	{
		runtime = (float)(clock() - start) / CLOCKS_PER_SEC;
		print_time(self, runtime, waittime, f);
	}
	self->state = IDLE;
}
