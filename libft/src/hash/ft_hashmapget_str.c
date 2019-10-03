/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hashmapget_str.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/24 12:54:42 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 17:16:39 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_str.h"

void	*ft_hashmapget_str(const t_hashmap *map, const char *key)
{
	return (ft_hashmapget(map, key, ft_strlen(key) + 1));
}
