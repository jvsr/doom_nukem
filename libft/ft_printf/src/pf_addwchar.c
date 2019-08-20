/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_addwchar.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 16:42:53 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	pf_addwchar(t_info *info, t_wchar c)
{
	t_wchar	bit;
	size_t	i;
	size_t	len;

	i = 1;
	len = ft_utf8len(c);
	bit = (0x80 | c) & 0x7f;
	if (len == 2)
		bit = (0xe0 | (c >> 6)) & 0xdf;
	else if (len == 3)
		bit = (0xf0 | (c >> 12)) & 0xef;
	else if (len == 4)
		bit = (0xf8 | (c >> 18)) & 0xf7;
	pf_addtobuff(info, (char *)&bit, 1);
	while (i < len)
	{
		i++;
		bit = (0xc0 | (c >> (6 * (len - i)))) & 0xbf;
		pf_addtobuff(info, (char *)&bit, 1);
	}
}
