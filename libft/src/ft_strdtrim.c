/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdtrim.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 14:53:11 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdtrim(const char *str, const char *dlm)
{
	char		*ret;
	long long	bytes[2];
	size_t		len;
	size_t		i;

	i = 0;
	if (str == NULL || dlm == NULL)
		return (NULL);
	len = ft_strlen(str);
	ft_chrsetbytes(bytes, (char *)dlm);
	while (ft_chrinbytes(bytes, str[i]) && str[i] != '\0')
		i++;
	if (i == len)
		return (ft_strnew(0));
	while (ft_chrinbytes(bytes, str[(len - 1)]) && (len - 1) > i)
		len--;
	ret = ft_strndup(&str[i], (size_t)(len - i));
	return (ret);
}
