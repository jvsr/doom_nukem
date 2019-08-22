/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termclr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/26 14:51:28 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:41:47 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminal.h"
#include "ft_string.h"

t_bool	ft_termclr_fd(int fd)
{
	return (ft_putstr_fd("\e[1;1H\e[2J\n", fd));
}
