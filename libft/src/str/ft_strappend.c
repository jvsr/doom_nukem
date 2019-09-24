/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strappend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/17 19:47:57 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:31:09 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_str.h"
#include "ft_mem.h"

void	ft_strappend(char **dst, const char *src)
{
	ft_pointerreplace((void **)dst, ft_strjoin(*dst, src));
}
