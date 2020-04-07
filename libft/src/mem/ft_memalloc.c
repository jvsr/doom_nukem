/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:13:10 by pholster      #+#    #+#                 */
/*   Updated: 2019/09/10 13:04:34 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_mem.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
