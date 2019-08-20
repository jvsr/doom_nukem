/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:28:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*f)(size_t, char))
{
	size_t	i;
	size_t	len;
	char	*ret;

	i = 0;
	if (f == NULL || str == NULL)
		return (NULL);
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
