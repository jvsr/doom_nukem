/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_formatdouble.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 14:30:25 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:27:01 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_string.h"
#include "ft_number.h"

static void	setdecimals(long double value, char *decimals, size_t n)
{
	size_t	i;
	int		rnd;
	int		num;

	i = 0;
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

static void	adddouble(t_info *info, long double value, size_t n)
{
	char		*decimals;
	intmax_t	num;

	decimals = ft_strnew(n + 1);
	if (decimals == NULL)
		return ;
	if (value < 0)
		value *= -1;
	num = (intmax_t)value;
	value -= num;
	setdecimals(value, decimals, n);
	num += (n == 0 && decimals[0] >= '5');
	pf_addnum(info, num);
	if (n != 0)
	{
		pf_addnstr(info, ".", 1);
		pf_addnstr(info, decimals, n);
	}
	ft_strdel(&decimals);
}

static void	formatdouble(t_info *info)
{
	double	value;

	value = va_arg(info->args, double);
	info->var_len = ft_numlen((long)value) + info->precision;
	info->isnegative = (value < 0);
	info->iszero = (value == 0);
	pf_formatpad(info);
	adddouble(info, value, info->precision);
}

static void	formatldouble(t_info *info)
{
	long double	value;

	value = va_arg(info->args, long double);
	info->var_len = ft_numlen((long)value) + info->precision;
	info->isnegative = (value < 0);
	info->iszero = (value == 0);
	pf_formatpad(info);
	adddouble(info, value, info->precision);
}

void		pf_formatdouble(t_info *info)
{
	if (info->var_type == DOUBLE)
		formatdouble(info);
	else
		formatldouble(info);
}
