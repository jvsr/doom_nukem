/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:13:10 by pholster       #+#    #+#                */
/*   Updated: 2019/09/10 13:04:34 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_memory.h"

void	*ft_memalloc(size_t size)
{
	void    *ap;

	ap = malloc(size);
	if (ap == NULL)
		return (NULL);
	ft_memset(ap, 0, size);
	return (ap);
}
