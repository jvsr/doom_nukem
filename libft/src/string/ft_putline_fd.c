/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putline_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 15:26:35 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:30:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_character.h"

t_bool	ft_putline_fd(const char *str, int fd)
{
	int		ret;
	size_t	len;
	size_t	half;

	if (str != NULL)
		len = ft_strnlen(str, 81);
	else
		len = 0;
	if (len > 80)
		return (TRUE);
	half = (80 - len) / 2;
	ret = ft_putnchar_fd('-', half, fd);
	ret += ft_putstr_fd(str, fd);
	ret += ft_putnchar_fd('-', half + (len + (half * 2) != 80), fd);
	ret += ft_putchar_fd('\n', fd);
	return (ret == 4);
}
