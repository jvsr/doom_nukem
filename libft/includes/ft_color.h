/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_color.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pholster <pholster@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 16:12:36 by pholster       #+#    #+#                */
/*   Updated: 2019/08/21 23:46:14 by pholster      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include <string.h>
# include <stdlib.h>

# include "ft_bool.h"
# include "ft_types.h"

typedef	struct	s_color
{
	t_uint8	r;
	t_uint8	g;
	t_uint8	b;
	t_uint8	a;
}				t_color;

char			*ft_colorstr(int color);
void			ft_colorhextorgba(t_color *color, t_uint32 hex);
t_uint32		ft_colorrgbatohex(t_color rgba);
int				ft_colorcode(const char *str);
int				ft_colorlcode(const char *str);
int				ft_colorncode(const char *str, size_t n);

#endif
