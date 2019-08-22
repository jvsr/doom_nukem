/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termclr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 14:51:28 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:43:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminal.h"

t_bool	ft_termclr(void)
{
	return (ft_termclr_fd(1));
}
