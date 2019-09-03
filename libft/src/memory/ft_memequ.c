/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 17:53:02 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:41:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

t_bool		ft_memequ(const void *str1, const void *str2, size_t len)
{
	return (ft_memcmp(str1, str2, len) == 0);
}
