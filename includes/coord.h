/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   coord.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:36:58 by jvisser       #+#    #+#                 */
/*   Updated: 2020/03/27 14:07:36 by euan          ########   odam.nl         */
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

typedef struct	s_bicoord
{
	t_coord		pos1;
	t_coord		pos2;
}				t_bicoord;

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

#endif
