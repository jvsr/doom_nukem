/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapdelone_str.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 16:59:50 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 17:27:19 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_string.h"

void	ft_hashmapdelone_str(const t_hashmap *map, const char *key,
			void (*del)(void *))
{
	ft_hashmapdelone(map, key, ft_strlen(key) + 1, del);
}
