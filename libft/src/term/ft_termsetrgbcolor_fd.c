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

#include "ft_term.h"
#include "ft_str.h"
#include "ft_char.h"
#include "ft_num.h"

t_bool	ft_termsetrgbcolor_fd(t_color rgb, int fd)
{
	if (ft_putstr_fd("\033[38;2;", fd) == FALSE)
		return (FALSE);
	if (ft_putnum_fd(rgb.r, fd) == FALSE)
		return (FALSE);
	if (ft_putchar_fd(';', fd) == FALSE)
		return (FALSE);
	if (ft_putnum_fd(rgb.g, fd) == FALSE)
		return (FALSE);
	if (ft_putchar_fd(';', fd) == FALSE)
		return (FALSE);
	if (ft_putnum_fd(rgb.b, fd) == FALSE)
		return (FALSE);
	return (ft_putchar_fd('m', fd));
}
