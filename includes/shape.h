/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/04 13:08:45 by jvisser        #+#    #+#                */
/*   Updated: 2019/09/09 15:19:40 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include <SDL2/SDL_rect.h>

typedef struct	s_circle
{
	size_t		d;
	SDL_Point	mid;
}				t_circle;

typedef struct	s_line
{
	float		x;
	float		y;
	float		equals;
}				t_line;

#endif
