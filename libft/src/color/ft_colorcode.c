/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_colorcode.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 16:13:28 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:40:56 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

ssize_t		ft_colorcode(const char *str)
{
	return (ft_colorncode(str, 16));
}
