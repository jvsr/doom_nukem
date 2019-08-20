/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pooljoin.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/17 22:45:56 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:24:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "threadpool.h"

void		ft_pooljoin(t_pool *pool)
{
	if (pool == NULL)
		return ;
	while (ft_pooldone(pool) == FALSE)
		;
}
