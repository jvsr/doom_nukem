/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strisempty.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/16 18:18:11 by pholster       #+#    #+#                */
/*   Updated: 2019/10/16 18:18:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_char.h"

t_bool		ft_strisempty(const char *str)
{
	size_t	len;

	len = ft_strislen(str, &ft_isspace);
	return (str[len] == '\0');
}
