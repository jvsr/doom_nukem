/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memreplace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 12:11:16 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:41:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memreplace(void **str1, const void *str2)
{
	ft_memdel(str1);
	*str1 = (void *)str2;
	return ((void *)str2);
}
