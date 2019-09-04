/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:28:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:43:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strmapi(const char *str, char (*f)(size_t, char))
{
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	len = ft_strlen(str);
	ret = ft_strnew(len);
	if (ret == NULL)
		return (NULL);
	while (i < len)
	{
		ret[i] = f(i, str[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
