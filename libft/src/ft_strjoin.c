/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 13:16:43 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	size_t			str1len;
	size_t			str2len;
	char			*str;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	str1len = ft_strlen(str1);
	str2len = ft_strlen(str2);
	str = ft_strnew(str1len + str2len);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, str1, str1len);
	ft_memcpy(&str[str1len], str2, str2len);
	return (str);
}
