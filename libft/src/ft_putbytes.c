/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbytes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 16:13:31 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_putbytes(void *bytes, size_t n)
{
	int		ret;
	char	*byts;

	byts = (char *)bytes;
	while (n > 0)
	{
		n--;
		ret = 0;
		ret += ft_putchar(((byts[n] & (1LL << 7)) != 0) + '0');
		ret += ft_putchar(((byts[n] & (1LL << 6)) != 0) + '0');
		ret += ft_putchar(((byts[n] & (1LL << 5)) != 0) + '0');
		ret += ft_putchar(((byts[n] & (1LL << 4)) != 0) + '0');
		ret += ft_putchar(((byts[n] & (1LL << 3)) != 0) + '0');
		ret += ft_putchar(((byts[n] & (1LL << 2)) != 0) + '0');
		ret += ft_putchar(((byts[n] & (1LL << 1)) != 0) + '0');
		ret += ft_putchar(((byts[n] & (1LL << 0)) != 0) + '0');
		if (n != 0)
			ret += ft_putchar(' ');
		if (ret != (8 + (n != 0)))
			return (FALSE);
	}
	return (TRUE);
}
