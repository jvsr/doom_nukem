/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:30:39 by pholster       #+#    #+#                */
/*   Updated: 2019/08/17 20:04:20 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		ft_atoi_base(const char *str, int base)
{
	char		*base_str;
	uintmax_t	result;
	int			sign;
	size_t		i;

	result = 0;
	base_str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (base < 2 || base > 36)
		return (0);
	i = ft_strislen(str, &ft_isspace);
	sign = (str[i] == '-' && base == 10) ? -1 : 1;
	i += (str[i] == '-' || str[i] == '+');
	while (ft_chrnin(base_str, str[i], base))
	{
		result = (result * base) + ft_chrindex(base_str, str[i]);
		if (result > (uintmax_t)(INTMAX_MAX + (sign == -1)))
			return (INTMAX_MAX + (sign == -1));
		i++;
	}
	return ((intmax_t)(result * sign));
}
