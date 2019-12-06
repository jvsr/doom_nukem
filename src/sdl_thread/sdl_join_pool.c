/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_join_pool.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 22:45:56 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:47:03 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_thread.h"

void		sdl_join_pool(t_pool const *pool)
{
	if (pool == NULL)
		return ;
	while (sdl_done_pool(pool) == FALSE)
		;
}
