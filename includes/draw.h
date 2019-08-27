/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 17:25:52 by ehollidg       #+#    #+#                */
/*   Updated: 2019/08/27 17:33:53 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "coord.h"
# include "libft/ft_bool.h"

typedef struct	s_rect
{
	t_coord			position;
	t_coord			size;
	t_bool			hasTexture;
	unsigned int	colour;
	t_img			img;
}				t_rect;

typedef struct s_img
{
	unsigned int	*pixels;
	int				width;
	int				height;
}				t_img;


#endif
