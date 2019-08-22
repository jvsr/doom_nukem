/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_chrindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 22:38:37 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:03:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_character.h"
#include "ft_memory.h"
#include "ft_string.h"

ssize_t		ft_chrindex(char *str, int c)
{
	char	*ptr;

	ptr = ft_memchr(str, c, ft_strlen(str));
	if (ptr == NULL)
		return (-1);
	return ((size_t)ptr - (size_t)str);
}
