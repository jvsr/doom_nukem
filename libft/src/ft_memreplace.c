/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memreplace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/20 12:11:16 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memreplace(void **str1, const void *str2)
{
	ft_memdel(str1);
	*str1 = (void *)str2;
	return ((void *)str2);
}
