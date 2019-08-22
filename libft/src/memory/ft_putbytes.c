/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putbytes.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/26 16:13:31 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:13:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_character.h"
#include "ft_string.h"

t_bool		ft_putbytes(void *bytes, size_t n)
{
	int		ret;
	char	*byts;

	if (bytes == NULL)
		return (ft_putstr(NULL));
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