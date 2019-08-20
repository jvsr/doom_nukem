/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunum_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:12:03 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_putunum_fd(uintmax_t value, int fd)
{
	return (ft_putunum_cbase_fd(value, 10, TRUE, fd));
}
