/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termcommand_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/19 12:21:06 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:42:12 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_term.h"
#include "ft_char.h"
#include "ft_str.h"
#include "ft_num.h"

t_bool	ft_termcommand_fd(int command, int fd)
{
	if (ft_putstr_fd("\033[", fd) == FALSE)
		return (FALSE);
	if (ft_putnum_fd(command, fd) == FALSE)
		return (FALSE);
	return (ft_putchar_fd('m', fd));
}
