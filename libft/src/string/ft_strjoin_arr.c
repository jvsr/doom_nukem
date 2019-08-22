/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_arr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 17:00:01 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:35:22 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_memory.h"

static size_t	totallen(char **arr)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (arr[i] != NULL)
	{
		len += ft_strlen(arr[i]);
		i++;
	}
	return (len + 1);
}

static char		*joinstrs(char *str, char **arr)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (arr[j] != NULL)
	{
		len = ft_strlen(arr[j]);
		ft_memcpy(&str[i], arr[j], len);
		i += len;
		j++;
	}
	return (str);
}

char			*ft_strjoin_arr(char **arr)
{
	char	*str;

	str = ft_strnew(totallen(arr));
	if (str == NULL)
		return (NULL);
	str = joinstrs(str, arr);
	return (str);
}
