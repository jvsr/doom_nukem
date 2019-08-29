/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:13:10 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:12:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ap;

	ap = (unsigned char *)malloc(size);
	if (ap == NULL)
		return (NULL);
	ft_memset(ap, 0, size);
	return (ap);
}
