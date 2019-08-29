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

#include "ft_character.h"
#include "ft_memory.h"

t_bool		ft_chrnin(const char *str, int c, size_t n)
{
	return (ft_memchr(str, c, n) != NULL);
}
