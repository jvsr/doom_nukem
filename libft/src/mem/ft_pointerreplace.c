/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_pointerreplace.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 12:11:16 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:41:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"

void	*ft_pointerreplace(void **ptr1, const void *ptr2)
{
	ft_memdel(ptr1);
	*ptr1 = (void *)ptr2;
	return ((void *)ptr2);
}
