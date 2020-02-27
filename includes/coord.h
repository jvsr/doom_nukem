/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coord.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:36:58 by jvisser        #+#    #+#                */
/*   Updated: 2020/02/20 19:22:56 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_H
# define COORD_H

# include <SDL2/SDL_rect.h>

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_tricoord
{
	t_coord		x;
	t_coord		y;
	t_coord		xy;
}				t_tricoord;

typedef struct	s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

#endif
