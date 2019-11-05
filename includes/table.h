/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   table.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 20:26:31 by jvisser        #+#    #+#                */
/*   Updated: 2019/11/05 20:34:30 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TABLE_H
# define TABLE_H

typedef struct s_tablepair
{
	const char	*id;
	void		*value;
}				t_tablepair;

typedef struct s_tablepair_int
{
	const char	*id;
	int			value;
}				t_tablepair_int;

#endif
