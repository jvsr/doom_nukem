/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_character.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 23:46:05 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHARACTER_H
# define FT_CHARACTER_H

# include "ft_bool.h"
# include <string.h>
# include <stdlib.h>

char		*ft_chrtostr(char c);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_getchar(void);
ssize_t		ft_chrdindex(const char *str, const char *dlm);
ssize_t		ft_chrindex(const char *str, int c);
t_bool		ft_chrdin(const char *str, const char *dlm);
t_bool		ft_chrin(const char *str, int c);
t_bool		ft_chrnin(const char *str, int c, size_t n);
void		ft_chrsetbytes(long long *bytes, const char *src);
t_bool		ft_chrinbytes(const long long *bytes, char c);
t_bool		ft_isalnum(int c);
t_bool		ft_isalpha(int c);
t_bool		ft_isascii(int c);
t_bool		ft_isblank(int c);
t_bool		ft_isdigit(int c);
t_bool		ft_islower(int c);
t_bool		ft_isprint(int c);
t_bool		ft_isspace(int c);
t_bool		ft_isupper(int c);
t_bool		ft_putchar(char c);
t_bool		ft_putchar_fd(char c, int fd);
t_bool		ft_putnchar(char c, size_t n);
t_bool		ft_putnchar_fd(char c, size_t n, int fd);

#endif
