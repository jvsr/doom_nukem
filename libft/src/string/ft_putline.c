/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putline.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 15:26:35 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:43:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_bool	ft_putline(const char *str)
{
	return (ft_putline_fd(str, 1));
}
