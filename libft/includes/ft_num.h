/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_num.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 23:47:18 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUM_H
# define FT_NUM_H

# include "ft_bool.h"
# include <stdint.h>
# include <string.h>

char		*ft_itoa_base(intmax_t value, int base);
char		*ft_itoa_cbase(intmax_t value, int base, t_bool up);
char		*ft_itoa(intmax_t value);
intmax_t	ft_atoi_base(const char *str, int base);
intmax_t	ft_atoi(const char *str);
size_t		ft_numlen_base(intmax_t value, int base);
size_t		ft_numlen(intmax_t value);
t_bool		ft_numin(const intmax_t *arr, intmax_t num, size_t len);
t_bool		ft_putnum_base_fd(intmax_t value, int base, int fd);
t_bool		ft_putnum_base(intmax_t value, int base);
t_bool		ft_putnum_cbase_fd(intmax_t value, int base, t_bool up, int fd);
t_bool		ft_putnum_cbase(intmax_t value, int base, t_bool up);
t_bool		ft_putnum_fd(intmax_t value, int fd);
t_bool		ft_putnum(intmax_t value);
t_bool		ft_inrange(intmax_t value, intmax_t min, intmax_t max);
float		ft_normalize(intmax_t value, const intmax_t *range,
				const intmax_t *outrange);
intmax_t	ft_constrain(intmax_t value, intmax_t min, intmax_t max);
intmax_t	ft_nearestnum(intmax_t value, intmax_t num1, intmax_t num2);
intmax_t	ft_overflow(intmax_t num, intmax_t min, intmax_t max);
intmax_t	ft_percentage(intmax_t num, intmax_t centage);
intmax_t	ft_pow(intmax_t num, intmax_t pow);
intmax_t	ft_sqrt(intmax_t nb);
intmax_t	ft_abs(intmax_t num);
intmax_t	ft_max(intmax_t num1, intmax_t num2);
intmax_t	ft_min(intmax_t num1, intmax_t num2);

#endif
