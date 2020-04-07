/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelmem.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/13 15:09:24 by pholster      #+#    #+#                 */
/*   Updated: 2019/08/24 17:08:00 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_lstdelmem(void *content, size_t size)
{
	(void)size;
	free(content);
}
