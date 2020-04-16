/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 20:26:31 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/13 17:22:16 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <stddef.h>

typedef struct	s_tablepair
{
	char *const	id;
	void *const	value;
}				t_tablepair;

typedef struct	s_tablepair_int
{
	char *const	id;
	int			value;
}				t_tablepair_int;

typedef struct	s_tablepair_ii
{
	int			id;
	void *const	value;
}				t_tablepair_ii;

char const		*find_tablepair_id(t_tablepair const *table, size_t table_size,
					void const *value);
void const		*find_tablepair_value(t_tablepair const *table,
					size_t table_size, char const *id);

int				find_tablepair_int_value(t_tablepair_int const *table,
					size_t table_size, const char *id);
char const		*find_tablepair_int_id(t_tablepair_int const *table,
					size_t table_size, int value);

int				find_tablepair_ii_id(t_tablepair_ii const *table,
					size_t table_size, void const *value);
void const		*find_tablepair_ii_value(t_tablepair_ii const *table,
					size_t table_size, int const id);

#endif
