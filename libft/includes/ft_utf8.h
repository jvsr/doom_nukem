/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_utf8.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:01:46 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTF8_H
# define FT_UTF8_H

# include "ft_bool.h"
# include <string.h>

typedef	int				t_wchar;

size_t		ft_utf8len(t_wchar c);
size_t		ft_utf8strlen(const t_wchar *str);
size_t		ft_utf8strnlen(const t_wchar *str, size_t n);
t_bool		ft_putnutf8str(const t_wchar *str, size_t n);
t_bool		ft_putnutf8str_fd(const t_wchar *str, size_t n, int fd);
t_bool		ft_pututf8_fd(t_wchar c, int fd);
t_bool		ft_pututf8(t_wchar c);
t_bool		ft_pututf8str(const t_wchar *str);
t_bool		ft_pututf8str_fd(const t_wchar *str, int fd);

#endif
