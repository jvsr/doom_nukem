/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cmath.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/22 13:11:10 by ehollidg       #+#    #+#                */
/*   Updated: 2019/11/22 13:11:10 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMATH_H
# define CMATH_H

typedef struct s_coord  t_coord;
typedef struct s_game   t_game;

typedef struct	s_line
{
	float		x;
	float		y;
	float		equals;
}				t_line;

t_coord		*get_collision(t_game *game,
                                    t_coord *a, t_coord *wall, t_coord *pos);

#endif
