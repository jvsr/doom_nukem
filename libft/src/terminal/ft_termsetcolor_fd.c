/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetcolor_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:43:35 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminal.h"
#include "ft_string.h"
#include "ft_number.h"
#include "ft_character.h"

t_bool	ft_termsetcolor_fd(t_color color, int fd)
{
	if (ft_putstr_fd("\e[38;5;", fd) == FALSE)
		return (FALSE);
	if (ft_putnum_fd(color, fd) == FALSE)
		return (FALSE);
	return (ft_putchar_fd('m', fd));
}
