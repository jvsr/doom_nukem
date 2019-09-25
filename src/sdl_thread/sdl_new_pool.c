/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_new_pool.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 20:31:26 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:47:52 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_printf.h"
#include "libft/ft_mem.h"

#include "sdl_thread.h"
#include "error.h"

static SDL_Thread	*alloc_thread(size_t number, t_thread *thread)
{
	SDL_Thread	*sdl_thread;
	char		*name;

	name = ft_strformat("Pool-Thread %zu", number);
	if (name == NULL)
		error_msg_errno("Failed to alloc thread name");
	sdl_thread = SDL_CreateThread(&sdl_manage_thread, name, thread);
	if (thread == NULL)
		error_msg_sdl(1, "Failed to alloc pool thread");
	free(name);
	return (sdl_thread);
}

static t_thread		*new_thread(t_pool *pool, size_t number)
{
	t_thread	*thread;

	thread = (t_thread *)ft_memalloc(sizeof(t_thread));
	if (thread == NULL)
		error_msg_errno("Failed to alloc thread struct");
	thread->number = number;
	thread->state = IDLE;
	thread->pool = pool;
	thread->thread = alloc_thread(number, thread);
	return (thread);
}

static void			alloc_threads(t_pool *pool, size_t size)
{
	size_t		current;

	current = size;
	while (current > 0)
	{
		current--;
		pool->threads[current] = new_thread(pool, current);
	}
	pool->suspended = FALSE;
}

static void			set_default(t_pool *pool, size_t size, t_bool tracktime)
{
	pool->size = size;
	pool->state = ACTIVE;
	pool->suspended = TRUE;
	pool->tracktime = tracktime;
}

t_pool				*sdl_new_pool(size_t size, t_bool tracktime)
{
	t_pool		*pool;

	pool = (t_pool *)ft_memalloc(sizeof(t_pool));
	if (pool == NULL)
		error_msg_errno("Failed to alloc thread pool");
	pool->threads = (t_thread **)ft_memalloc(sizeof(t_thread *) * size);
	if (pool->threads == NULL)
		error_msg_errno("Failed to alloc thread array");
	set_default(pool, size, tracktime);
	alloc_threads(pool, size);
	return (pool);
}
