/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memindex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/07/14 14:56:10 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 20:41:40 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_types.h"

ssize_t	ft_memindex(const void *str, char c, size_t len)
{
	void	*ptr;
	size_t	ptr_addr;
	size_t	str_addr;

	ptr = ft_memchr(str, c, len);
	if (ptr == NULL)
		return (-1);
	ptr_addr = (size_t)ptr;
	str_addr = (size_t)str;
	if (str_addr < ptr_addr)
		return (ptr_addr - str_addr);
	return (str_addr - ptr_addr);
}
