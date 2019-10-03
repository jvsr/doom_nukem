/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_que_pool_front.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 21:13:06 by pholster       #+#    #+#                */
/*   Updated: 2019/09/25 15:34:15 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft/ft_mem.h"

#include "sdl_thread.h"

static void		get_lock(t_pool *pool, t_thread_state *state)
{
	*state = atomic_exchange(&(pool->state), LOCKED);
	while (*state == LOCKED)
		*state = atomic_exchange(&(pool->state), LOCKED);
}

t_bool			sdl_que_pool_front(t_pool *pool, void (*f)(),
									size_t param_count, ...)
{
	va_list				params;
	t_thread_state		state;
	t_task				*task;

	if (param_count > 4 || pool->terminating)
		return (FALSE);
	get_lock(pool, &state);
	va_start(params, param_count);
	task = sdl_new_task(f, param_count, params);
	va_end(params);
	if (sdl_que_pool(pool, TRUE, task) == FALSE)
		ft_memdel((void **)&task);
	atomic_store(&(pool->state), state);
	return (task != NULL);
}
