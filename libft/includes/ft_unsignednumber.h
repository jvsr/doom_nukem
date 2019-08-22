/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unsignednumber.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 21:49:59 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UNSIGNEDNUMBER_H
# define FT_UNSIGNEDNUMBER_H

# include "ft_bool.h"
# include <string.h>
# include <stdint.h>

size_t		ft_unumlen_base(uintmax_t value, int base);
size_t		ft_unumlen(uintmax_t value);
t_bool		ft_putunum_base_fd(uintmax_t value, int base, int fd);
t_bool		ft_putunum_base(uintmax_t value, int base);
t_bool		ft_putunum_cbase_fd(uintmax_t value, int base, t_bool up, int fd);
t_bool		ft_putunum_cbase(uintmax_t value, int base, t_bool up);
t_bool		ft_putunum_fd(uintmax_t value, int fd);
t_bool		ft_putunum(uintmax_t value);

#endif
