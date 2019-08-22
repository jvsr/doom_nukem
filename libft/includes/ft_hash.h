/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hash.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/22 13:06:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_H
# define FT_HASH_H

# include "ft_bool.h"
# include "ft_list.h"
# include <string.h>

typedef struct	s_hashmap
{
	size_t			size;
	t_list			**arr;
	size_t			(*f)(char *);
}				t_hashmap;

t_hashmap		*ft_hashmapnew(size_t size, size_t (*f)(char *));
t_bool			ft_hashmapadd(t_hashmap *hashmap, char *key);
size_t			ft_hashsdbm(char *str);
size_t			ft_hashdjb2(char *str);
size_t			ft_hashdjb2a(char *str);
size_t			ft_hashsdbm_nocase(char *str);
size_t			ft_hashdjb2_nocase(char *str);
size_t			ft_hashdjb2a_nocase(char *str);

#endif
