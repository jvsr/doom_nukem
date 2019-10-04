/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ishexstr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 16:07:33 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:30:12 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_char.h"

t_bool		ft_ishexstr(const char *str)
{
	size_t	len;

	len = ft_strislen(str, &ft_ishex);
	return (str[len] == '\0');
}
