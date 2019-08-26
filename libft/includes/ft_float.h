/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_float.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/23 11:27:11 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

# include "ft_bool.h"
# include <string.h>

# define MAX_DOUBLE_PRECISION 10

t_bool		ft_putdouble_fd(long double value, size_t n, int fd);
t_bool		ft_putdouble(long double value, size_t n);

#endif
