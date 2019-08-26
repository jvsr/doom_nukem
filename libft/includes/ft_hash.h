/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hash.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/24 17:27:13 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HASH_H
# define FT_HASH_H

# include "ft_bool.h"
# include <string.h>

typedef struct	s_hashlist
{
	void				*value;
	char				*key;
	struct s_hashlist	*next;
}				t_hashlist;

typedef struct	s_hashmap
{
	size_t				size;
	t_hashlist			**arr;
	size_t				(*f)(char *);
}				t_hashmap;

t_hashmap		*ft_hashmapnew(size_t size, size_t (*f)(char *));
size_t			ft_hashsdbm(char *str);
size_t			ft_hashdjb2(char *str);
size_t			ft_hashdjb2a(char *str);
size_t			ft_hashsdbm_nocase(char *str);
size_t			ft_hashdjb2_nocase(char *str);
size_t			ft_hashdjb2a_nocase(char *str);
void			*ft_hashmapget(t_hashmap *map, char *key);
t_bool			ft_hashmapadd(t_hashmap *map, char *key, void *value);
void			ft_hashmapdel(t_hashmap *map, void (*del)(void *));
void			ft_hashmapdelone(t_hashmap *map, char *key,
					void (*del)(void *));

#endif
