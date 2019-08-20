/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utf8strlen.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_utf8strlen(const t_wchar *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		len += ft_utf8len(str[i]);
		i++;
	}
	return (len);
}
