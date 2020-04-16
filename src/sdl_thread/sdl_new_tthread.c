/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_new_tthread.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:40:35 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:02:47 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"
#include "libft/ft_str.h"

#include "sdl_thread.h"
#include "error.h"

t_tthread		*sdl_new_tthread(t_tpool *pool, size_t num, int (*f)(void *))
{
	t_tthread		*thread;
	char			*name;

	name = ft_strformat("Pool-Thread %zu", num);
	if (name == NULL)
		error_msg_errno("Failed to alloc thread name");
	thread = ft_memalloc(sizeof(t_tthread));
	if (thread == NULL)
		error_msg_errno("Failed to alloc thread struct");
	thread->pool = pool;
	thread->num = num;
	thread->id = SDL_CreateThread(f, name, thread);
	if (thread->id == NULL)
		error_msg_sdl(13, "Failed to alloc worker thread");
	ft_strdel(&name);
	return (thread);
}
