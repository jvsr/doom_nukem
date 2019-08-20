/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 18:07:07 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool		ft_strnin(const char **arr, const char *str, size_t n)
{
	return (ft_strnindex(arr, str, n) != -1);
}
