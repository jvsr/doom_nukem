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

static size_t	strtotallen(const char *str, const char *find, size_t len,
					size_t seglen)
{
	char	*ptr;
	size_t	found;

	found = 0;
	ptr = ft_strstr(str, find);
	while (ptr != NULL)
	{
		ptr = ft_strstr(ptr + 1, find);
		found++;
	}
	return (len - (seglen * found));
}

static char		*strset(const char *str, const char *find, const char *replace,
					const size_t *lentable)
{
	size_t	i;
	size_t	len;
	char	*new;
	char	*ptr;

	i = 0;
	new = ft_strnew(lentable[2]);
	if (new == NULL)
		return (NULL);
	ptr = ft_strstr(str, find);
	while (ptr != NULL)
	{
		len = (size_t)ptr - (size_t)str;
		ft_strncpy(&new[i], str, len);
		ft_strcpy(&new[i + len], replace);
		i += len + lentable[1];
		str += len + lentable[0];
		ptr = ft_strstr(str, find);
	}
	ft_strcpy(&new[i], str);
	return (new);
}

char			*ft_strreplace(const char *str, const char *find,
					const char *replace)
{
	size_t	findlen;
	size_t	replacelen;
	size_t	totallen;
	size_t	lentable[3];

	findlen = ft_strlen(find);
	replacelen = ft_strlen(replace);
	totallen = ft_strlen(str);
	lentable[0] = findlen;
	lentable[1] = replacelen;
	lentable[2] = strtotallen(str, find, totallen, findlen + replacelen);
	return (strset(str, find, replace, lentable));
}
