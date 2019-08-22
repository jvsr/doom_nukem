/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strarrsortac.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 23:50:25 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:40:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stringarray.h"
#include "ft_string.h"

t_bool		ft_strarrsortac(char *current, char *str)
{
	int		result;

	result = ft_strcmp(current, str);
	return (result < 0 && result != 0);
}
