/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putmemory.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 13:03:15 by exam           #+#    #+#                */
/*   Updated: 2019/08/21 21:14:02 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_character.h"
#include "ft_string.h"

static t_bool	putbit(unsigned char c, int size)
{
	char	*base_str;

	base_str = "0123456789abcdef";
	if (size <= 0)
		return (TRUE);
	if (size > 1)
	{
		if (putbit(c / 16, size - 1) == FALSE)
			return (FALSE);
	}
	return (ft_putchar(base_str[c % 16]));
}

static t_bool	putcontent(const unsigned char *content, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (ft_isprint(content[i]) == FALSE)
		{
			if (ft_putchar('.') == FALSE)
				return (FALSE);
		}
		else
		{
			if (ft_putchar(content[i]) == FALSE)
				return (FALSE);
		}
		i++;
	}
	return (ft_putchar('\n'));
}

static t_bool	putreport(const unsigned char *mem, size_t i)
{
	size_t		printed;

	printed = (i % 16) + (i % 2);
	if (printed == 0)
		printed = 16;
	if ((i % 2) != 0)
	{
		if (ft_putnchar(' ', 3) == FALSE)
			return (FALSE);
	}
	if (printed != 0)
	{
		if (ft_putnchar(' ', (8 - (printed / 2)) * 5) == FALSE)
			return (FALSE);
	}
	return (putcontent(&mem[i - printed + (i % 2)], printed - (i % 2)));
}

t_bool			ft_putmemory(const void *addr, size_t size)
{
	const unsigned char	*mem;
	size_t				i;

	i = 0;
	mem = addr;
	if (addr == NULL)
		return (ft_putstr(NULL));
	while (i < size)
	{
		i++;
		if (putbit(mem[i - 1], 2) == FALSE)
			return (FALSE);
		if ((i % 2) == 0)
		{
			if (ft_putchar(' ') == FALSE)
				return (FALSE);
		}
		if ((i % 16) == 0 || i == size)
		{
			if (putreport(mem, i) == FALSE)
				return (FALSE);
		}
	}
	return (TRUE);
}
