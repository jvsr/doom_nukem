/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnutf8str.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/20 12:01:12 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/21 20:44:32 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utf8.h"

t_bool	ft_putnutf8str(const t_wchar *str, size_t n)
{
	return (ft_putnutf8str_fd(str, n, 1));
}
