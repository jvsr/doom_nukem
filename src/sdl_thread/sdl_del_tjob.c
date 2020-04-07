/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_del_tjob.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 16:41:22 by pholster      #+#    #+#                 */
/*   Updated: 2020/04/06 12:03:25 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_mem.h"

#include "sdl_thread.h"

void		*sdl_del_tjob(t_tjob **job, t_bool delete_task)
{
	if (job == NULL || *job == NULL)
		return (NULL);
	if (delete_task == TRUE)
		sdl_del_ttask(&(*job)->task);
	ft_memdel((void**)job);
	return (NULL);
}
