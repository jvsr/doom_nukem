/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_new_tjob.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:40:19 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:03:04 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "sdl_thread.h"
#include "error.h"

t_tjob	*sdl_new_tjob(t_ttask *task)
{
	t_tjob	*job;

	job = ft_memalloc(sizeof(t_tjob));
	if (job == NULL)
		error_msg_errno("Failed to alloc job struct");
	job->task = task;
	return (job);
}
