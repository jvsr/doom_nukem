/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_new_tqueue.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:40:19 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:40:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "sdl_thread.h"
#include "error.h"

t_tqueue	*sdl_new_tqueue(void)
{
	t_tqueue	*queue;

	queue = ft_memalloc(sizeof(t_tqueue));
	if (queue == NULL)
		error_msg_errno("Failed to alloc queue struct");
	queue->lock = SDL_CreateMutex();
	if (queue->lock == NULL)
		error_msg_sdl(13, "Failed to alloc queue 'lock'");
	queue->cond_empty = SDL_CreateCond();
	if (queue->cond_empty == NULL)
		error_msg_sdl(13, "Failed to alloc queue 'cond_empty'");
	queue->cond_not_empty = SDL_CreateCond();
	if (queue->cond_not_empty == NULL)
		error_msg_sdl(13, "Failed to alloc queue 'cond_not_empty'");
	return (queue);
}
