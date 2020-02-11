/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_del_ttask.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:57:18 by pholster       #+#    #+#                */
/*   Updated: 2020/02/07 16:57:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "sdl_thread.h"

void	*sdl_del_ttask(t_ttask **task)
{
	if (task == NULL || *task == NULL)
		return (NULL);
	SDL_DestroyMutex((*task)->lock);
	SDL_DestroyCond((*task)->cond_completed);
	ft_memdel((void**)task);
	return (NULL);
}
