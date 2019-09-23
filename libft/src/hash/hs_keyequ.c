/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hs_keyequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 11:45:46 by pholster       #+#    #+#                */
/*   Updated: 2019/08/29 11:45:46 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hash.h"
#include "ft_memory.h"

t_bool	hs_keyequ(const t_hashlist *entry, const void *key, size_t keysize)
{
	if (entry->keysize != keysize)
		return (FALSE);
	return (ft_memequ(entry->key, key, keysize));
}
