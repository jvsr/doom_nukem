/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coord.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:36:58 by jvisser        #+#    #+#                */
/*   Updated: 2019/08/28 17:59:22 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_H
# define COORD_H

typedef struct	s_coord
{
	float		x;
	float		y;
}				t_coord;

typedef struct	s_pixel
{
	int			x;
	int			y;
}				t_pixel;

typedef struct	s_vec
{
	float		x;
	float		y;
	float		z;
}				t_vec;

#endif
