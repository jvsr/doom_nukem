/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_getnextline.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 16:25:35 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t		ft_getnextline(const int fd, char **line)
{
	return (ft_getnextdline(fd, line, '\n'));
}
