/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 20:26:31 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/06 17:26:41 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

# include <stddef.h>
typedef struct	s_tablepair
{
	const char	*id;
	void		*value;
}				t_tablepair;

typedef struct	s_tablepair_int
{
	const char	*id;
	int			value;
}				t_tablepair_int;

typedef struct	s_ables
{
	
}				t_tables;

void		*find_tablepair_value(t_tablepair *table, size_t table_size,
										const char *id);

int			find_tablepair_int_value(t_tablepair_int *table, size_t table_size,
										const char *id);
const char	*find_tablepair_int_id(t_tablepair_int *table, size_t table_size,
										int value);

#endif
