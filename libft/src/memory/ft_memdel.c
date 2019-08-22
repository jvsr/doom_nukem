/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:08:14 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap == NULL || *ap == NULL)
		return ;
	free(*ap);
	*ap = NULL;
}
