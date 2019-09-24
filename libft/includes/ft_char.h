/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_char.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 23:46:05 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHAR_H
# define FT_CHAR_H

# include <string.h>
# include <stdlib.h>

# include "ft_bool.h"
# include "ft_types.h"

char		*ft_chrtostr(char c);
char		ft_tolower(char c);
char		ft_toupper(char c);
char		ft_getchar(void);
ssize_t		ft_chrdindex(const char *str, const char *dlm);
ssize_t		ft_chrindex(const char *str, char c);
t_bool		ft_chrdin(const char *str, const char *dlm);
t_bool		ft_chrin(const char *str, char c);
t_bool		ft_chrnin(const char *str, char c, size_t n);
void		ft_chrsetbytes(t_uint64 *bytes, const char *src);
t_bool		ft_chrinbytes(const t_uint64 *bytes, char c);
t_bool		ft_isalnum(char c);
t_bool		ft_isalpha(char c);
t_bool		ft_isascii(char c);
t_bool		ft_isblank(char c);
t_bool		ft_isdigit(char c);
t_bool		ft_islower(char c);
t_bool		ft_isprint(char c);
t_bool		ft_isspace(char c);
t_bool		ft_isupper(char c);
t_bool		ft_putchar(char c);
t_bool		ft_putchar_fd(char c, int fd);
t_bool		ft_putnchar(char c, size_t n);
t_bool		ft_putnchar_fd(char c, size_t n, int fd);

#endif
