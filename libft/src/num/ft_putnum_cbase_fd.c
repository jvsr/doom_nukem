/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnum_cbase_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:17:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"
#include "ft_char.h"

t_bool	ft_putnum_cbase_fd(intmax_t value, int base, t_bool up, int fd)
{
	char		*base_str;
	uintmax_t	num;

	if (up == TRUE)
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	num = (value < 0 && base == 10) ? -value : value;
	if (base < 2 || base > 36)
		return (TRUE);
	if (value < 0 && base == 10)
	{
		if (ft_putchar_fd('-', fd) == FALSE)
			return (FALSE);
	}
	if (num > (uintmax_t)(base - 1))
	{
		if (ft_putnum_cbase_fd((num / base), base, up, fd) == FALSE)
			return (FALSE);
	}
	num = base_str[(num % base)];
	return (ft_putchar_fd(num, fd));
}
