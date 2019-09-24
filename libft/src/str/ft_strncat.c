/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 10:48:45 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:37:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

char	*ft_strncat(char *str1, const char *str2, size_t n)
{
	size_t	str1len;
	size_t	str2len;

	str1len = ft_strlen(str1);
	str2len = ft_strnlen(str2, n);
	ft_memcpy(&str1[str1len], str2, str2len);
	str1[(str1len + str2len)] = '\0';
	return (str1);
}
