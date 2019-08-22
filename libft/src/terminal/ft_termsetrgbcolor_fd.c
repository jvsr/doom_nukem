/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetrgbcolor_fd.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:44:57 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_terminal.h"
#include "ft_string.h"
#include "ft_character.h"
#include "ft_number.h"

t_bool	ft_termsetrgbcolor_fd(t_color r, t_color g, t_color b, int fd)
{
	if (ft_putstr_fd("\e[38;2;", fd) == FALSE)
		return (FALSE);
	if (ft_putnum_fd(r, fd) == FALSE)
		return (FALSE);
	if (ft_putchar_fd(';', fd) == FALSE)
		return (FALSE);
	if (ft_putnum_fd(g, fd) == FALSE)
		return (FALSE);
	if (ft_putchar_fd(';', fd) == FALSE)
		return (FALSE);
	if (ft_putnum_fd(b, fd) == FALSE)
		return (FALSE);
	return (ft_putchar_fd('m', fd));
}
