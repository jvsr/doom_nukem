/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrnin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:03:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_str.h"
#include "ft_mem.h"

t_bool		ft_chrnin(const char *str, char c, size_t n)
{
	size_t	len;

	len = ft_strnlen(str, n);
	return (ft_memchr(str, c, len + (len != n)) != NULL);
}
