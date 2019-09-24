/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnchar_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:05:27 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:40:44 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_mem.h"
#include "ft_str.h"

static size_t	putnchar_8(char c, size_t n, int fd)
{
	char	str[8];

	ft_memset(&str, c, sizeof(str));
	while (n > 8)
	{
		if (ft_putnstr_fd(str, 8, fd) == FALSE)
			return (FALSE);
		n -= 8;
	}
	return (n);
}

t_bool			ft_putnchar_fd(char c, size_t n, int fd)
{
	if (n > 8)
		n = putnchar_8(c, n, fd);
	while (n > 0)
	{
		if (ft_putchar_fd(c, fd) == FALSE)
			return (FALSE);
		n--;
	}
	return (TRUE);
}
