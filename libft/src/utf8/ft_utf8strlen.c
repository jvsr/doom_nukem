/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utf8strlen.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:44:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utf8.h"

size_t	ft_utf8strlen(t_wchar *str)
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
