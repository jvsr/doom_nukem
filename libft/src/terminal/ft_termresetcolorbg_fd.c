/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termresetcolorbg_fd.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:42:42 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminal.h"
#include "ft_string.h"

t_bool	ft_termresetcolorbg_fd(int fd)
{
	return (ft_putstr_fd("\e[49m\e[K", fd));
}
