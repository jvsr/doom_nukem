/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrnin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:42:01 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_chrnin(const char *str, int c, size_t n)
{
	if (str == NULL)
		return (FALSE);
	return (ft_memchr(str, c, n) != NULL);
}
