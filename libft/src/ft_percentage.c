/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_percentage.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/21 12:24:50 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "typedefs.h"

intmax_t	ft_percentage(intmax_t num, intmax_t centage)
{
	return ((num * centage) / 100);
}
