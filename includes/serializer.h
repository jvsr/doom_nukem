/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   serializer.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 11:10:53 by ehollidg       #+#    #+#                */
/*   Updated: 2019/10/07 11:10:53 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <stdlib.h>
# include "libft/ft_bool.h"

typedef union	u_convert
{
	char			c;
	short			s;
	int				i;
	long			l;
	float			f;
	double			d;
	unsigned char	*stream;
}				t_convert;

t_bool			write_struct(char *loc,void *obj, size_t size);
unsigned char	*read_struct(char *loc);
void			add_type(unsigned char **bytes,
								size_t *b_size, t_convert *val, size_t v_size);
void			add_char(unsigned char **bytes, size_t *b_size, char c);
void			add_short(unsigned char **bytes, size_t *b_size, short s);
void			add_int(unsigned char **bytes, size_t *b_size, int i);
void			add_long(unsigned char **bytes, size_t *b_size, long l);
void			add_float(unsigned char **bytes, size_t *b_size, float f);
void			add_double(unsigned char **bytes, size_t *b_size, double d);

#endif