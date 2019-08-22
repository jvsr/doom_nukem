/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strreplace.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 17:48:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:43:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static size_t	strtotallen(char *str, char *find, char *replace, size_t len)
{
	char	*ptr;
	size_t	found;
	size_t	findlen;
	size_t	replen;

	found = 0;
	findlen = ft_strlen(find);
	replen = ft_strlen(replace);
	ptr = ft_strstr(str, find);
	while (ptr != NULL)
	{
		ptr = ft_strstr(ptr + 1, find);
		found++;
	}
	return (len - (findlen * found) + (replen * found));
}

static char		*strset(char *ret, char *str, char *find, char *replace)
{
	size_t	i;
	size_t	replen;
	size_t	findlen;
	size_t	len;
	char	*ptr;

	i = 0;
	replen = ft_strlen(replace);
	findlen = ft_strlen(find);
	ptr = ft_strstr(str, find);
	while (ptr != NULL)
	{
		len = (size_t)ptr - (size_t)str;
		ft_strncpy(&ret[i], str, len);
		ft_strcpy(&ret[i + len], replace);
		i += len + replen;
		str += len + findlen;
		ptr = ft_strstr(str, find);
	}
	ft_strcpy(&ret[i], str);
	return (ret);
}

char			*ft_strreplace(char *str, char *find, char *replace)
{
	size_t	newlen;
	char	*ret;

	newlen = strtotallen(str, find, replace, ft_strlen(str));
	ret = ft_strnew(newlen);
	if (ret == NULL)
		return (NULL);
	return (strset(ret, str, find, replace));
}
