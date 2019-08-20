/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:35:18 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)str);
	while (i < len && str[i] != '\0' && needle[j] != '\0')
	{
		if (j > 0 && str[i - j] != needle[0])
			j--;
		if (j > 0 && str[i] != needle[j])
			j--;
		if (str[i] == needle[j])
			j++;
		i++;
	}
	if (str[i - 1] == needle[j])
		j++;
	if (needle[j] == '\0')
		return ((char *)&str[i - j]);
	return (NULL);
}
