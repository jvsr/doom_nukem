/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strislen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 13:45:24 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

size_t	ft_strislen(const char *str, t_bool (*f)(int))
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && f(str[len]))
		len++;
	return (len);
}