/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_termsetrgbcolor_fd.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/18 14:42:21 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_termsetrgbcolor_fd(t_color r, t_color g, t_color b, int fd)
{
	ft_putstr_fd("\e[38;2;", fd);
	ft_putnum_fd(r, fd);
	ft_putchar_fd(';', fd);
	ft_putnum_fd(g, fd);
	ft_putchar_fd(';', fd);
	ft_putnum_fd(b, fd);
	ft_putchar_fd('m', fd);
}
