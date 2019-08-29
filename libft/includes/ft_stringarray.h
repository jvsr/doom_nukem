/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_stringarray.h                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:36:27 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGARRAY_H
# define FT_STRINGARRAY_H

# include "ft_bool.h"
# include "ft_list.h"
# include <string.h>
# include <stdarg.h>

size_t		ft_strarrlen(const char **arr);
size_t		ft_strarrnlen(const char **arr, size_t n);
char		**ft_strarrcpy_var(char **dst, size_t count, ...);
char		**ft_strarrcpy(char **dst, const char **src);
char		**ft_strarrdup_var(size_t count, ...);
char		**ft_strarrdup(const char **arr);
char		**ft_strarrnew(size_t size);
t_list		*ft_strarrtolst(const char **arr);
void		ft_strarrdel(char ***arr);
void		ft_strarrrev(char **arr);
void		ft_strarrtolower(char **arr);
void		ft_strarrtoupper(char **arr);
t_bool		ft_strarrsortac(const char *current, const char *str);
t_bool		ft_putstrarr(const char **arr);
void		ft_strarrsort(char **const arr,
				t_bool (*f)(const char *, const char *));
void		ft_strarrsortrev(char **arr,
				t_bool (*f)(const char *, const char *));
void		ft_strarrnsort(char **arr,
				t_bool (*f)(const char *, const char *), size_t n);
void		ft_strarrnsortrev(char **arr,
				t_bool (*f)(const char *, const char *), size_t n);
char		**ft_strfldnew(size_t x, size_t y, char c);
t_bool		ft_strfldvalid(const char **arr, size_t x, size_t y,
				const char *dlm);

#endif
