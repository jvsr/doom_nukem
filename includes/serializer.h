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
# include "types.h"

# define RESOURCE_PATH "resources/data/"

typedef enum e_endian		t_endian;
typedef struct s_list		t_list;
typedef struct s_setting	t_setting;

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

typedef struct	s_binary
{
	unsigned char	*content;
	t_uint64		c_size;
	unsigned char	*header;
	t_uint64		h_size;
}				t_binary;

typedef struct	s_binary_read
{
	unsigned char	*bytes;
	size_t			header_pos;
	size_t			content_pos;
	size_t			header_size;
	t_endian		endian;
}				t_binary_read;

t_binary		*new_binary(void);
void			del_binary(t_binary **bin);
t_binary_read	*new_binary_read(const char *loc, char const *exec_path);
void			del_binary_read(t_binary_read **bin_r);
t_bool			write_struct(char *loc, t_binary *bin, char const *exec_path);
unsigned char	*read_struct(const char *loc, char const *exec_path);
void			add_type(unsigned char **bytes, t_uint64 *b_size,
											t_convert *val, t_uint64 v_size);
void			add_char(char c, t_binary *bin);
void			add_short(short s, t_binary *bin);
void			add_int(int i, t_binary *bin);
void			add_long(long l, t_binary *bin);
void			add_float(float f, t_binary *bin);
void			add_double(double d, t_binary *bin);
void			add_string(char *string, t_binary *bin);
void			add_list_gen(t_list *lst, t_binary *bin);
unsigned char	read_char(t_binary_read *bin_r);
short			read_short(t_binary_read *bin_r);
int				read_int(t_binary_read *bin_r);
long			read_long(t_binary_read *bin_r);
float			read_float(t_binary_read *bin_r);
double			read_double(t_binary_read *bin_r);
char			*read_string(t_binary_read *bin_r);
t_list			*read_list_gen(t_binary_read *bin_r, t_uint64 d_size);
void			finish_bin(t_binary *bin);
t_endian		detect_endian(void);
long			read_header(t_binary_read *bin_r);
void			swap_bytes(void *v_bytes, t_uint64 size);

t_setting		*read_settings(char const *exec_path);
void			write_settings(t_setting *settings, char const *exec_path);

#endif
