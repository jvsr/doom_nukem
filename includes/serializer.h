/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   serializer.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/07 11:10:53 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/10 18:24:19 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_H
# define SERIALIZER_H

# include <stdlib.h>
# include "libft/ft_bool.h"
# include "types.h"
# include "coord.h"
# include "rinfo.h"

# define RESOURCE_PATH "resources/data/"

# define HEADER_AMT 7
# define MAP_HEADER 5318008

typedef enum e_endian			t_endian;
typedef struct s_list			t_list;
typedef struct s_setting		t_setting;

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
	size_t			file_size;
}				t_binary_read;

t_binary		*new_binary(void);
void			del_binary(t_binary **bin);
t_binary_read	*new_binary_read(const char *loc,
									t_bool add_header, char const *exec_path);
void			del_binary_read(t_binary_read **bin_r);
t_bool			write_struct(char *loc, t_binary *bin, char const *exec_path);
unsigned char	*read_struct(const char *loc,
								char const *exec_path, size_t *file_size);
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
void			add_anim(t_anim *anim, t_binary *bin);
void			add_coord(t_coord *coord, t_binary *bin);
void			add_decal(t_decal *decal, t_binary *bin);
void			add_decal_list(t_list *lst, t_binary *bin);
void			add_wall(t_wall *wall, t_binary *bin, t_map *map);
void			add_obj(t_object *obj, t_binary *bin);
void			add_enemy(t_enemy *enemy, t_binary *bin);
void			add_sec(t_sector *sec, t_binary *bin, t_map *map);
void			add_map(t_map *map, t_binary *bin);
unsigned char	read_char(t_binary_read *bin_r);
short			read_short(t_binary_read *bin_r);
int				read_int(t_binary_read *bin_r);
long			read_long(t_binary_read *bin_r);
float			read_float(t_binary_read *bin_r);
double			read_double(t_binary_read *bin_r);
t_coord			read_coord(t_binary_read *bin_r);
t_anim			read_anim(t_binary_read *bin_r, t_object *obj);
char			*read_string(t_binary_read *bin_r);
t_list			*read_list_gen(t_binary_read *bin_r, t_uint64 d_size);
t_decal			read_decal(t_binary_read *bin_r);
t_list			*read_decal_list(t_binary_read *bin_r);
t_wall			*read_wall(t_binary_read *bin_r, t_map *map);
t_object		*read_obj(t_binary_read *bin_r);
t_enemy			*read_enemy(t_object *obj, t_binary_read *bin_r);
t_sector		*read_sec(t_binary_read *bin_r, t_map *map);
t_map			*read_map(t_binary_read *bin_r);
void			finish_bin(t_binary *bin);
t_endian		detect_endian(void);
long			read_header(t_binary_read *bin_r);
void			swap_bytes(void *v_bytes, t_uint64 size);
t_setting		*read_settings(char const *exec_path);
void			write_settings(t_setting *settings, char const *exec_path);
void			write_map_struct(t_map *map, const char *loc,
						const char *exec_path);
t_map			*read_map_struct(char const *loc, char const *exec_path);

#endif
