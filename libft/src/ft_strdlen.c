/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 15:20:03 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strdlen(const char *str, const char *dlm)
{
	size_t		len;
	long long	bytes[2];

	len = 0;
	if (str == NULL || dlm == NULL)
		return (0);
	ft_chrsetbytes(bytes, (char *)dlm);
	while (str[len] != '\0' && ft_chrinbytes(bytes, str[len]) == FALSE)
		len++;
	return (len);
}
