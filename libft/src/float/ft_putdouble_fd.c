/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putdouble_fd.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/27 17:15:03 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:06:55 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float.h"
#include "ft_memory.h"
#include "ft_character.h"
#include "ft_string.h"
#include "ft_number.h"

static void	setdecimals(long double value, char *decimals, size_t n)
{
	size_t	i;
	int		rnd;
	int		num;

	i = 0;
	num = 0;
	while (i < (n + 1))
	{
		value *= 10;
		num = (int)value;
		decimals[i] = num + '0';
		value -= num;
		i++;
	}
	i--;
	rnd = (num >= 5);
	while (i > 0)
	{
		i--;
		decimals[i] += rnd;
		if (decimals[i] == ('9' + 1))
			decimals[i] = '0';
		else
			rnd = 0;
	}
}

t_bool		ft_putdouble_fd(long double value, size_t n, int fd)
{
	char		decimals[MAX_DOUBLE_PRECISION + 1];
	long long	num;

	ft_bzero(decimals, MAX_DOUBLE_PRECISION + 1);
	if (n > MAX_DOUBLE_PRECISION)
		n = MAX_DOUBLE_PRECISION;
	if (value < 0)
	{
		if (ft_putchar_fd('-', fd) == FALSE)
			return (FALSE);
		value *= -1;
	}
	num = (long long)value;
	value -= num;
	setdecimals(value, decimals, n);
	if (ft_putnum_fd(num + (n == 0 && decimals[0] >= '5'), fd) == FALSE)
		return (FALSE);
	if (n == 0)
		return (TRUE);
	if (ft_putchar_fd('.', fd) == FALSE)
		return (FALSE);
	return (ft_putnstr_fd(decimals, n, fd));
}
