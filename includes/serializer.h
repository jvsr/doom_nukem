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

typedef struct s_list	t_list;

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

typedef struct 	s_binary
{
	unsigned char	*content;
	unsigned char	*header;
	size_t			c_size;
	size_t			h_size;
}				t_binary;

t_bool			write_struct(char *loc,void *obj, size_t size);
unsigned char	*read_struct(char *loc);
void			add_type(unsigned char **bytes,
								size_t *b_size, t_convert *val, size_t v_size);
void			add_char(char c, t_binary *bin);
void			add_short(short s, t_binary *bin);
void			add_int(int i, t_binary *bin);
void			add_long(long l, t_binary *bin);
void			add_float(float f, t_binary *bin);
void			add_double(double d, t_binary *bin);
void			add_string(char *string, t_binary *bin);
void			add_list_gen(t_list *lst, t_binary *bin);
unsigned char	read_char(unsigned char *bytes);
short			read_short(unsigned char *bytes);
int				read_int(unsigned char *bytes);
long			read_long(unsigned char *bytes);
float			read_float(unsigned char *bytes);
double			read_double(unsigned char *bytes);
char			*read_string(unsigned char *header, unsigned char *bytes);
t_list			*read_list_gen(unsigned char *header, unsigned char *bytes,
						size_t header_pos, size_t d_size);
void			finish_bin(t_binary *bin);

#endif