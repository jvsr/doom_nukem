/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_memory.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/09 13:03:15 by exam           #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putbit(unsigned char c, int size)
{
	char	*base_str;

	base_str = "0123456789abcdef";
	if (size <= 0)
		return ;
	if (size > 1)
		putbit(c / 16, size - 1);
	ft_putchar(base_str[c % 16]);
}

static void	putcontent(unsigned char *content, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (ft_isprint(content[i]) == FALSE)
			ft_putchar('.');
		else
			ft_putchar(content[i]);
		i++;
	}
	ft_putchar('\n');
}

void		ft_print_memory(const void *addr, size_t size)
{
	unsigned char	*mem;
	size_t			printed;
	size_t			i;

	i = 0;
	mem = (unsigned char *)addr;
	while (i < size)
	{
		i++;
		putbit(mem[i - 1], 2);
		if ((i % 2) == 0)
			ft_putchar(' ');
		if ((i % 16) == 0 || i == size)
		{
			printed = (i % 16) + (i % 2);
			if (printed == 0)
				printed = 16;
			if ((i % 2) != 0)
				ft_putnchar(' ', 3);
			if (printed != 0)
				ft_putnchar(' ', (8 - (printed / 2)) * 5);
			putcontent(&mem[i - printed + (i % 2)], printed - (i % 2));
		}
	}
}
