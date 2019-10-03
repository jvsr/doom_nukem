/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termresetcolor_fd.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:42:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include "ft_str.h"

t_bool	ft_termresetcolor_fd(int fd)
{
	return (ft_putstr_fd("\033[39m\033[K", fd));
}
