/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_string.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 23:47:50 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "ft_bool.h"
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

# define BUFF_SIZE	42

typedef struct	s_gnl
{
	int				fd;
	char			*str;
	size_t			len;
	struct s_gnl	*next;
}				t_gnl;

char			**ft_strdsplit(char *str, char *dlm);
char			**ft_strsplit(char *str, char c);
char			*ft_strcat(char *str1, char *str2);
char			*ft_strchr(char *str, int c);
char			*ft_strcpy(char *dst, char *src);
char			*ft_strdtrim(char *str, char *dlm);
char			*ft_strdup(char *str);
char			*ft_strjoin_arr(char **arr);
char			*ft_strjoin_var(size_t count, ...);
char			*ft_strjoin(char *str1, char *str2);
char			*ft_strmap(char *str, char (*f)(char));
char			*ft_strmapi(char *str, char (*f)(size_t, char));
char			*ft_strncat(char *str1, char *str2, size_t n);
char			*ft_strncpy(char *dst, char *src, size_t n);
char			*ft_strndup(char *str, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(char *str, char *needle, size_t len);
char			*ft_strrchr(char *str, int c);
char			*ft_strreplace(char *str, char *find, char *replace);
char			*ft_strstr(char *str, char *needle);
char			*ft_strsub(char *str, size_t start, size_t len);
char			*ft_strtolower(char *str);
char			*ft_strtoupper(char *str);
char			*ft_strtrim(char *str);
t_bool			ft_isdigitstr(char *str);
int				ft_strcmp_nocase(char *str1, char *str2);
int				ft_strcmp(char *str1, char *str2);
int				ft_strncmp_nocase(char *str1, char *str2, size_t n);
int				ft_strncmp(char *str1, char *str2, size_t n);
size_t			ft_strdlen(char *str, char *dlm);
size_t			ft_strislen(char *str, t_bool (*f)(int));
size_t			ft_strlcat(char *dst, char *src, size_t size);
size_t			ft_strlen(char *str);
size_t			ft_strmatchlen_nocase(char *str1, char *str2);
size_t			ft_strmatchlen(char *str1, char *str2);
size_t			ft_strnlen(char *str, size_t n);
ssize_t			ft_strindex(char **arr, char *str);
ssize_t			ft_strnindex(char **arr, char *str, size_t n);
void			ft_strappend(char **dst, char *src);
void			ft_strclr(char *str);
void			ft_strdel(char **as);
void			ft_striter(char *str, void (*f)(char *));
void			ft_striteri(char *str, void (*f)(size_t, char *));
void			ft_strrev(char *str);
t_bool			ft_strequ_nocase(char *str1, char *str2);
t_bool			ft_strequ(char *str1, char *str2);
t_bool			ft_strin(char **arr, char *str);
t_bool			ft_strmatch(char *str, char *needle);
t_bool			ft_strnequ_nocase(char *str1, char *str2, size_t n);
t_bool			ft_strnequ(char *str1, char *str2, size_t n);
t_bool			ft_strnin(char **arr, char *str, size_t n);
t_bool			ft_putendl_fd(char *str, int fd);
t_bool			ft_putendl(char *str);
t_bool			ft_puterror(char *str);
t_bool			ft_putline_fd(char *str, int fd);
t_bool			ft_putline(char *str);
t_bool			ft_putnstr_fd(char *str, size_t n, int fd);
t_bool			ft_putnstr(char *str, size_t n);
t_bool			ft_putstr_fd(char *str, int fd);
t_bool			ft_putstr(char *str);
size_t			ft_wrddcount(char *str, char *dlm);
ssize_t			ft_getnextdline(int fd, char **line, char dlm);
ssize_t			ft_getnextline(int fd, char **line);
ssize_t			ft_readfile(int fd, char **str);

#endif
