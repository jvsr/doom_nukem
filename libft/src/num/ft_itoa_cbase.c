/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_cbase.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:52:39 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:15:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_num.h"
#include "ft_str.h"

char	*ft_itoa_cbase(intmax_t value, int base, t_bool up)
{
	uintmax_t	num;
	size_t		len;
	char		*base_str;
	char		*str;

	num = (value < 0 && base == 10) ? -value : value;
	len = ft_numlen_base(value, base);
	if (base < 2 || base > 36)
		return (NULL);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	if (up == TRUE)
		base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else
		base_str = "0123456789abcdefghijklmnopqrstuvwxyz";
	while ((len - (value < 0 && base == 10)) != 0)
	{
		str[len - 1] = base_str[(num % base)];
		num = num / base;
		len--;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}
