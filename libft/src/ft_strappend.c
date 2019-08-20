/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strappend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 19:47:57 by pholster       #+#    #+#                */
/*   Updated: 2019/08/10 16:25:08 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strappend(char **dst, const char *src)
{
	ft_memreplace((void **)dst, ft_strjoin(*dst, src));
}
